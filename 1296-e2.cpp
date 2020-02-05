#include <iostream>
#include <set>
#include <vector>

#define tipo int

#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

tipo union_set(tipo a, tipo b) {
    // vector<bool> aux(30, 0);
    // for (int el : a) {
    //     aux[el] = true;
    // }

    // for (int el : b) {
    //     if (aux[el])
    //         continue;
    //     aux[el] = true;
    //     a.push_back(el);
    // }

    // return a;
    return a | b;
}

struct st {
    int size;
    vector<tipo > arr;
    vector<tipo > lazy;

    st(int n) {
        size = 1;
        int copia = n;
        while(copia > 1) copia >>= 1, size <<= 1;
        if (size < n) 
            size <<= 1;

        arr.resize(size*2);
        lazy.resize(size*2);
    }

    void propagate(int nodo) {
        if (nodo < size) {
            lazy[nodo<<1] = union_set(lazy[nodo<<1], lazy[nodo]);
            lazy[nodo<<1|1] = union_set(lazy[nodo<<1|1], lazy[nodo]);
        }
        arr[nodo] = union_set(lazy[nodo], arr[nodo]);
        lazy[nodo] = {};
    }

    void update(int a, int b, int val, int nodo=1, int l=0, int r=0) {
        if (nodo == 1) {
            r = size-1;
        }
        // cout << l << " " << r << endl;

        // caso 2: [l, r] esta excluido de [a, b]
        if (r < a || l > b) {
            return;
        }

        // caso 1: [l, r] esta incluido en [a, b]
        if (l >= a && r <= b) {
            tipo sval = 1<<val;
            lazy[nodo] = union_set(lazy[nodo], sval);
            return;
        }

        this->propagate(nodo);

        // caso 3: llamada a los hijos
        int m = (l + r) / 2;
        update(a, b, val, nodo<<1, l, m);
        update(a, b, val, nodo<<1|1, m+1, r);
    }

    tipo query(int a, int b, int nodo=1, int l=0, int r=0)  {
        if (nodo == 1) {
            r = size-1;
        }
        // cout << l << " " << r << endl;

        // caso 2: [l, r] esta excluido de [a, b]
        if (r < a || l > b) {
            tipo vacio = 0;
            return vacio;
        }

        this->propagate(nodo);
        // caso 1: [l, r] esta incluido en [a, b]
        if (l >= a && r <= b) {
            return arr[nodo];
        }

        // caso 3: llamada a los hijos
        int m = (l+r) / 2;
        tipo ans1 = query(a, b, nodo<<1, l, m);
        tipo ans2 = query(a, b, nodo<<1|1, m+1, r);

        return union_set(ans1, ans2);
    }
};

void resolver(int n, string s) {
    vector<int> abecedario[26];
    vector<int> colores(n);
    st excluidos(n);

    forn (i, n) {
        int key = s[i] - 'a';
        abecedario[key].push_back(i);
    }

    forn (i, 26) {

        forn (j, abecedario[i].size()) {
            int pos = abecedario[i][j];

            int color = 1;
            auto excluidos_pos = excluidos.query(pos, pos);

            forn (i, 30) {
                if (excluidos_pos & 1<<i)
                    if (i == color)
                        color++;
            }

            colores[pos] = color;

            if (pos > 0)
                excluidos.update(0, pos-1, color);
        }
    }

    int maximo = 1;
    forn (i, n) maximo = max(maximo, colores[i]);
    
    cout << maximo << endl;
    forn (i, n) cout << colores[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; string s;
    cin >> n >> s;

    resolver(n, s);
}