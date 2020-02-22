#include <iostream>
#include <vector>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

struct d {
    int t, l, h;
};

d intersect(d a, d b) {
    a.l = max(a.l, b.l);
    a.h = min(a.h, b.h);

    return a;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;

        vector<d> clientes(n);
        forn (i, n) {
            int t, l, h;
            cin >> t >> l >> h;
            clientes[i] = {t, l, h};
        }

        {
            int j = 0;
            forn (i, n) {
                if (clientes[i].t == clientes[j].t) {
                    clientes[j] = intersect(clientes[i], clientes[j]);
                } else {
                    clientes[++j] = clientes[i];
                }
            }
            n = j+1;
            clientes.resize(n);
        }

        int T = 0;
        int L = m;
        int H = m;
        bool factible = true;
        forn (i, n) {
            int h = clientes[i].h;
            int l = clientes[i].l;
            int t = clientes[i].t;

            if (l > h) {
                factible = false;
                break;
            }

            int dt = t - T;

            int hposible = H + dt;
            int lposible = L - dt;

            if (hposible < l || lposible > h) {
                factible = false;
                break;
            }

            H = min(h, hposible);
            L = max(l, lposible);

            T = t;
        }

        cout << (factible ? "YES" : "NO") << endl;
    }
}