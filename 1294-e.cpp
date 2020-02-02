#include <iostream>
#include <cstring>
#define forn(i, n) for(int i=0; i<n; i++)
#define coord(x, y) (y*m+x)

using namespace std;

const int MAXN = 2e5+5;
int tablero[MAXN];
int columna[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    forn(i, n) forn(j, m) cin >> tablero[coord(j, i)];

    int ans = 0;
    forn (j, m) {
        memset(columna, 0, n*sizeof(int));

        int inicio = j + 1;
        int fin    = inicio + m * (n-1);
        forn (i, n) {
            int casilla = tablero[coord(j, i)];
            if (casilla % m != inicio % m || casilla < inicio || casilla > fin) {
                continue;
            }

            int movimientos = (casilla - inicio) / m;
            // for (;casilla != inicio;movimientos++, casilla-=m);

            int desired = i - movimientos;

            desired = desired < 0 ? n + desired : desired;

            columna[desired]++;
        }

        int minimo = n+5;
        forn (i, n) {
            int movimientos = n - columna[i] + i;
            minimo = min(minimo, movimientos);
        }

        // cout << "COLUMNA " << j+1 << " " << maximo << " " << pos << endl;

        // int movimientos = n - maximo + pos;
        ans += minimo;
    }

    cout << ans << endl;
}