#include <iostream>
#include <cstring>
#define forn(i,n) for(int i=0;i<n;i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)
#define forra(i,a,n) for(int i=n-1; i>=a; i--)
#define limpiar(x) memset(x, 0, sizeof(x))

using namespace std;

int main() {
    int q;
    cin >> q;

    while(q--) {
        int n; string s;
        cin >> n >> s;

        int L = 1;
        int U = n;
        int max_lis[n];
        limpiar(max_lis);
        int min_lis[n];
        limpiar(min_lis);
        forn (i, n-1) {
            if (s[i] == '<') {
                max_lis[i] = L++;
            }
        }
        int prv_i = -1;
        forn (i, n-1) {
            if (prv_i == -1 && s[i] == '<') {
                prv_i = i;
            }
            if (prv_i != -1 && s[i] == '>') {
                forra(j, prv_i, i+1) {
                    min_lis[j] = U--;
                }
                prv_i = -1;
            }
        }

        if (prv_i != -1) {
            forra(j, prv_i, n) {
                min_lis[j] = U--;
            }
        }

        {
            int l = L;
            int u = n;
            forn (i, n) {
                if (max_lis[i] != 0) {
                    continue;
                }

                max_lis[i] = u--;
            }
        }

        {
            int l = 1;
            int u = U;
            forn (i, n) {
                if (min_lis[i] != 0)
                    continue;

                min_lis[i] = u--;
            }
        }

        forn (i, n) cout << min_lis[i] << " ";
        cout << endl;
        forn (i, n) cout << max_lis[i] << " ";
        cout << endl;
    }
}