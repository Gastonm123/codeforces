#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define forn(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> maximos;
    vector<int> minimos;
    vector<ii> numeros;
    bool ascents[n];

    long long total = 0;
    int cant_numeros = n;

    forn (i, n) {
        int m;
        cin >> m;

        int minimo = 1e6 + 5;
        int maximo = -1;
        bool ascent = false;
        forn (j, m) {
            int sij;
            cin >> sij;

            minimo = min(minimo, sij);
            maximo = max(maximo, sij);

            if (sij > minimo) {
                ascent = true;
            }
        }

        if (!ascent) {
            maximos.push_back(maximo);
            minimos.push_back(minimo);
            numeros.push_back(make_pair(minimo, maximo));
        } else {
            total += 2*cant_numeros-1;
            cant_numeros--;
        }
    }

    sort(maximos.begin(), maximos.end());
    sort(minimos.begin(), minimos.end());

    long long aditamento = 0;
    forn (i, numeros.size()) {
        ii rango = numeros[i];

        int a = -1;
        int b = cant_numeros;
        while (a < b - 1) { 
            int m = (a + b) / 2;

            if (maximos[m] <= rango.first) {
                a = m;
            } else {
                b = m;
            }
        }

        aditamento += (cant_numeros - b);

        a = -1;
        b = cant_numeros;
        while (a < b - 1) {
            int m = (a + b) / 2;

            if (minimos[m] < rango.second) {
                a = m;
            } else {
                b = m;
            }
        }

        aditamento += b;
    }

    total += aditamento / 2;
    cout << total << endl;
}