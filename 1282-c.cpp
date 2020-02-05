#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

const int MAXN = 2e5+5;
typedef pair<int ,int> ii;
typedef vector<int>::iterator it;

vector<int> vfaciles;
vector<int> vdificiles;
int n, t, f, d;

int maximo(long long tiempo, it faciles, it dificiles) {
    if (tiempo > t) {
        return -1;
    }

    if (faciles != vfaciles.end() && *faciles <= tiempo) {
        // obligatorio
        int ans = maximo(tiempo+f, faciles+1, dificiles);
        return (ans == -1 ? -1 : ans+1);
    }
    if (dificiles != vdificiles.end() && *dificiles <= tiempo) {
        int ans;
        if (faciles != vfaciles.begin())
            ans = maximo(tiempo+d-f, faciles-1, dificiles+1);
        else {
            ans = maximo(tiempo+d, faciles, dificiles+1);
            ans = (ans == -1 ? -1 : ans+1);
        }

        return ans;
    }

    int ans = 0;
    if (faciles != vfaciles.end()) {
        ans = maximo(tiempo+f, faciles+1, dificiles);
        ans = (ans == -1 ? 0 : ans+1);
    } else if (dificiles != vdificiles.end()) {
        ans = maximo(tiempo+d, faciles, dificiles+1);
        ans = (ans == -1 ? 0 : ans+1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    while(m--) {
        cin >> n >> t >> f >> d;

        vector<bool> problemas(n);
        forn (i, n) {
            bool problema;
            cin >> problema;
            problemas[i] = problema;
        }

        forn (i, n) {
            int tiempo;
            cin >> tiempo;

            if (problemas[i]) {
                vdificiles.push_back(tiempo);
            } else {
                vfaciles.push_back(tiempo);
            }
        }

        sort(vfaciles.begin(), vfaciles.end());
        sort(vdificiles.begin(), vdificiles.end());

        int ans = maximo(0, vfaciles.begin(), vdificiles.begin());

        cout << (ans == -1 ? 0 : ans) << endl;

        vfaciles.clear();
        vdificiles.clear();
    }
}