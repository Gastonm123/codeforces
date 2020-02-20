#include <iostream>
#include <vector>
#define forn(i, n) for(int i=0;i<n; i++)

using namespace std;

typedef long long ll;

struct dp {
    int fi;
    int se;
    int th;
};

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;

        ll L = m;
        ll H = m;
        ll T = 0;
        bool factible = true;
        ll t_ant = 2e9;
        ll delta = 0;
        vector<dp> querys;
        int j = 0;
        forn (i, n) {
            ll t, l, h;
            cin >> t >> l >> h;

            if (t == t_ant) {
                querys[j] = {t, min(l, querys[i].)}
            } else {
                querys[++i] = {t, l, h};
            }
            t_ant = t;
        }

        for (auto v : querys) {

            if (t != t_ant) {
                delta = t - T;
            }

            t_ant = t;
            int pL = L;
            int pH = H;
            if (factible) {
                if (h <= L) {
                    L = max(l, L-delta);
                    H = max(h, H-delta);
                } else if (l >= H) {
                    L = min(l, L+delta);
                    H = min(h, H+delta);
                } else {
                    if (l <= L) {
                        L = max(l, L-delta);
                    } else {
                        L = min(l, L+delta);
                    }
                    if (h <= H) {
                        H = max(h, H-delta);
                    } else {
                        H = min(h, H+delta);
                    }
                }

                if (h < L || l > H) {
                    factible = false;
                }
            }
            delta -= max(abs(pL - L), abs(pH - H));
            // cout << H << " " << L << endl;
            T = t;
        }

        cout << (factible ? "YES" : "NO") << endl;
    }
}