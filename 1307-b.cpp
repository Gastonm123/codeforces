#include <iostream>
#define forn(i, n) for(int i=0;i<n;i++)
using namespace std;

const int MAXN = 1e5+5;
int numeros[MAXN];

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, x;
        cin >> n >> x;

        int minimo = 2e9;
        forn (i, n) {
            cin >> numeros[i];

            int saltos = x / numeros[i];
            if (x % numeros[i]) {
                if (saltos == 0)
                    saltos++;
                saltos++;
            }

            minimo = min(minimo, saltos);
        }

        cout << minimo << endl;
    }
}