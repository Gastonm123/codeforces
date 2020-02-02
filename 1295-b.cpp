#include <iostream>
#include <cstring>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

const int MAXN = 2e5+5;
bool s[MAXN];
int apariciones[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while(t--) {
        memset(apariciones, 0, sizeof(apariciones));

        int n, x;
        string input;
        cin >> n >> x >> input;

        int maximo = 0;
        int minimo = 0;
        int hackeado = false;
        int tendencia;
        int contador = 0;
        forn (i, n) {
            contador += (input[i] == '0' ? 1 : -1);
            maximo = max(maximo, contador);
            minimo = min(minimo, contador);

            apariciones[contador+n]++;
            // cout << "APARECIO EL " << contador << " " << apariciones[contador+n] << "VECES";
        }

        tendencia = contador;

        if (x >= 0) {

            // if (maximo < x) {
            //     if (tendencia > 0) {
            //         x %= tendencia;
            //         if (x == 0) {
            //             x = tendencia;
            //         }
            //     } else {
            //         cout << "0" << endl;
            //         continue;
            //     }
            // } 
            
            // if (tendencia == 0) {
            //     cout << "-1" << endl;
            //     continue;
            // }
            while(x > maximo && tendencia > 0) x -= tendencia;
            
            int ans = 0;

            int temp = x;
            while (x+n >= 0 && x+n <= MAXN && apariciones[x+n] > 0) {
                if (tendencia == 0) {
                    ans = -1;
                    break;
                }
                ans += apariciones[x+n];
                // cout << "APARECIO " << apariciones[x+n] << " VECES EL " << x << endl;
                x -= tendencia;
            }

            x = temp + tendencia;
            while (x+n >= 0 && x+n <= MAXN && apariciones[x+n] > 0) {
                if (tendencia == 0) {
                    ans = -1;
                    break;
                }
                ans += apariciones[x+n];
                // cout << "APARECIO " << apariciones[x+n] << " VECES EL " << x << endl;
                x += tendencia;
            }

            cout << ans << endl;
        } else {
            // if (minimo > x) {
            //     if (tendencia < 0) {
            //         x %= tendencia;
            //         if (x == 0) {
            //             x = tendencia;
            //         }
            //     } else {
            //         cout << "0" << endl;
            //         continue;
            //     }
            // } 
            
            // if (tendencia == 0) {
            //     cout << "-1" << endl;
            //     continue;
            // }
            while(x < minimo && tendencia < 0) x -= tendencia;

            int ans = 0;
            int temp = x;
            while (x+n >= 0 && x+n <= MAXN && apariciones[x+n] > 0) {
                if (tendencia == 0) {
                    ans = -1;
                    break;
                }
                ans += apariciones[x+n];
                // cout << "APARECIO " << apariciones[x+n] << " VECES EL " << x << endl;
                x -= tendencia;
            }


            // cout << "LOS VALORES DE INTERES SON " << x << " " << minimo << endl;
            x = temp + tendencia;

            while(x+n >= 0 && x+n <= MAXN && apariciones[x+n] > 0) {
                if (tendencia == 0) {
                    ans = -1;
                    break;
                }
                ans += apariciones[x+n];
                x += tendencia;
            }

            cout << ans << endl;
        }
    }
}