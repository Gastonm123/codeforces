#include <iostream>
#include <vector>
#include <utility>
#define x first
#define y second
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

typedef pair<int, int> ii;

const int MAXN = 3e5+5;

struct st {
    vector<int> arr;
    vector<int> lazy;
    int size;

    st(int n) {
        int n_2 = 1;
        int copia = n;
        while(n>1) n_2<<=1, n>>=1;
        if (copia > n_2) n_2<<=1;

        size = n_2;
        arr.resize(n_2*2, 0);
        lazy.resize(n_2*2, 0);
    }

    void propagate(int nodo) {
        if (nodo < size) {
            lazy[nodo<<1] += lazy[nodo];
            lazy[nodo<<1|1] += lazy[nodo];
        }

        arr[nodo] += lazy[nodo];
        lazy[nodo] = 0;
    }

    void update(int a, int b, int l=0, int r=0, int nodo=1) {
        if (nodo == 1) r = size-1;
        // cout << "\t" << l << " " << r << endl;

        // caso 1: el rango [l, r] esta contenido en [a, b]
        if (l>=a && r<=b) {
            lazy[nodo] += 1;
            return;
        }

        // caso 2: el rango [l, r] esta fuera del rango [a, b]
        if (l>b || r<a) {
            return;
        }

        this->propagate(nodo);

        // caso 3: el rango [l, r] es mas grande que [a, b]
        int m = (l + r) / 2;

        update(a, b, l, m, nodo<<1);
        update(a, b, m+1, r, nodo<<1|1);
    }

    int query(int a, int b, int l=0, int r=0, int nodo=1) {
        if (nodo == 1) r = size-1;

        // caso 2: el rango [l, r] esta fuera del rango [a, b]
        if (l>b || r<a) {
            return 0;
        }

        this->propagate(nodo);

        // caso 1: el rango [l, r] esta contenido en [a, b]
        if (l>=a && r<=b) {

            return arr[nodo];
        }

        // caso 3: el rango [l, r] es mas grande que [a, b]
        int m = (l + r) / 2;

        int left = query(a, b, l, m, nodo<<1);
        int right = query(a, b, m+1, r, nodo<<1|1);

        return left + right;
    }
};

ii resultados[MAXN];

int main() {
    int n, q;
    cin >> n >> q;

    st arbol(n+q);

    int llamadas=0;
    vector<int> posiciones(n+1);
    forn (i, n) posiciones[i+1] = n-i-1;

    while(q--) {
        int contacto;
        cin >> contacto;
        // cout << "QUERY " << llamadas << ":";
        // cout << "(" << contacto << ")" << endl;

        resultados[contacto].x = 1;

        int posicion = posiciones[contacto];
        int corrimiento = arbol.query(posicion, posicion);

        posiciones[contacto] = n+llamadas;
        int posicion_inicial = posicion > n-1 ? 1 : contacto;

        resultados[contacto].y = max(resultados[contacto].y, posicion_inicial+corrimiento);

        if (posicion+1 <= posiciones[contacto]-1) {
            arbol.update(posicion+1, posiciones[contacto]-1);
        }

        llamadas++;
    }

    forn (i, n) {
        int j = i+1;
        resultados[j].x = resultados[j].x != 0 ? 1 : j;

        int posicion = posiciones[j];
        int corrimiento = arbol.query(posicion, posicion);

        int posicion_inicial = posicion > n-1 ? 1 : j;
        resultados[j].y = max(resultados[j].y, posicion_inicial+corrimiento);

        cout << resultados[j].x << " " << resultados[j].y << endl;
    }
}