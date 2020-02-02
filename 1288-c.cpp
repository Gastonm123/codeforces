#include <iostream>
#define forn(i, a, n) for(int i=a; i<=n; i++)

using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1005;

int tablita[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    int n, m;

    cin >> n >> m;

    forn (i, 1, n) forn(j, i, n) dp[i][j] = 1;

    forn (i, 1, m) {
        // armar tablita
        forn (a, 1, n) {
            int suma = 0;
            forn (b, 1, n) {
                suma += dp[b][a];
                suma %= MOD;
                tablita[b][a] = suma;
            }
        } 


        forn (a, 1, n)
            forn (b, a, n) {
                // calcular la suma desde a hasta b
                long long suma = tablita[b][b];
                suma -= tablita[a-1][b];
                suma += dp[a][b-1];
                suma %= MOD;

                dp[a][b] = suma;
            }
    }

    cout << dp[1][n] << endl;
}