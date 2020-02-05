#include <iostream>
#include <vector>
#include <map>
#include <utility>

#define forn(i, n) for(int i=0; i<n; i++)
using namespace std;


typedef pair<int, int> ii;

ii o(char a) {
    if (a == 'U') 
        return make_pair(0, 1);
    if (a == 'D')
        return make_pair(0, -1);
    if (a == 'L')
        return make_pair(-1, 0);
    if (a == 'R')
        return make_pair(1, 0);
}

void resolver(int n, string s) {
    ii position = {0, 0};
    map<ii, vector<int>> visitados;
    ii respuesta = {-1, -1};
    int minimo = n+5;
    visitados[position] = {-1};

    forn (i, n) {
        ii movimiento = o(s[i]);
        position = make_pair(
            position.first + movimiento.first,
            position.second + movimiento.second
        );

        if (!visitados.count(position))
            visitados[position] = {};

        visitados[position].push_back(i);
    }

    for (auto v : visitados) {
        auto vv = v.second;
        forn (i, vv.size()-1) {
            int distancia = vv[i+1] - vv[i]+1;
            if (distancia < minimo) {
                respuesta = make_pair(vv[i]+1, vv[i+1]);
                minimo = distancia;
            }
        }
    }

    if (respuesta.first == -1) {
        cout << "-1" << endl;
    } else {
        cout << respuesta.first+1 << " " << respuesta.second+1 << endl;
    }
    // cout << maximo << endl;
}

int main() {
    int t;
    cin >> t;

    // cout << "1 4" << endl;
    // cout << "1 4" << endl;
    // cout << "-1" << endl;
    // cout << "-1" << endl;
    // return 0;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        // cout << resolver(n, s) << endl;
        resolver(n, s);
    }
}