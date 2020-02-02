#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define forn(i, n ) for(int i = 0; i < n; i++)

using namespace std;

vector<int> valores[8];
vector<int> resultado[2];

int d;
int tope;

vector<int> filtrar(vector<int> filtrado, int pos) {
    vector<int> ans;

    for (int a : filtrado) {
        if (valores[pos][a] >= tope)
            ans.push_back(a);
    }

    return ans;
}

bool mayores(int pos, vector<int> primero, vector<int> segundo) {
    if (primero.size() == 0 || segundo.size() == 0) {
        return false;
    }

    if (pos >= d) {
        resultado[0] = primero;
        resultado[1] = segundo;
        return true;
    }

    vector<int> interseccion_primero = filtrar(primero, pos);
    bool res1 = mayores(pos+1, interseccion_primero, segundo);

    if (res1) {
        return res1;
    }

    vector<int> interseccion_segundo = filtrar(segundo, pos);
    bool res2 = mayores(pos+1, primero, interseccion_segundo);

    return res2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n >> d;

    forn (i, n)
        forn (j, d) {
            int valor;
            cin >> valor;

            valores[j].push_back(valor);
        }

    vector<int> todos(n);
    forn(i, n) todos[i] = i;

    int a = -1, b = 1e9+1;
    while (b > a+1) {
        int m = (a+b) / 2;

        tope = m;
        if (mayores(0, todos, todos)) {
            a = m;
        } else {
            b = m;
        }
    }

    tope = a;
    mayores(0, todos, todos);
    
    int r1 = resultado[0][0] + 1;
    int r2 = resultado[1][0] + 1;

    cout << r1 << " " << r2 << endl;
}