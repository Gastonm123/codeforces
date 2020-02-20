#include <iostream>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

const int MAXN = 1e9+5;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;

        int a = -1, b = MAXN;
        while (a < b-1) {
            int m = (a + b ) / 2;

            long long dist_a = ll(x) + ll(p) * m;
            long long dist_b = ll(y) - ll(q) * m;
            if (dist_a <= dist_b) {
                a = m;
            } else {
                b = m;
            }
        }

            long long dist_a = ll(x) + ll(p) * a;
            long long dist_b = ll(y) - ll(q) * a;
        if (dist_a < dist_b) {
            cout << "-1" << endl;
        } else {
            cout << a << endl;
        }
    }
}