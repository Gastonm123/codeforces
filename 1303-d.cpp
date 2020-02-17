#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

typedef vector<long long>::iterator it;
typedef map<long long, int>::iterator itm;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n; int m;
        cin >> n >> m;

        vector<long long> numero;
        forn (i, 64) {
            if (n>>i & 1) {
                numero.push_back(1ll<<i);
            }
        }

        map<long long, int> seq;
        forn (i, m) {
            int nro = 0;
            cin >> nro;

            if (seq.count(nro)) {
                seq[nro]++;
            } else {
                seq[nro] = 1;
            }
        }

        itm ps = seq.begin();
        it pn = numero.begin();
        int cortes = 0;

        for (;ps!=seq.end()&&pn!=numero.end();ps=seq.begin()) {
            if (*pn < ps->first) {
                long long nro = ps->first;

                while (nro > *pn) {
                    seq[nro]--;
                    nro /= 2;
                    seq[nro] += 2;
                    cortes++;
                }

                if (ps->second == 0) {
                    seq.erase(ps);
                }
                continue;
            }

            if (*pn == ps->first) {
                ps->second--;
                pn++;

                if (ps->second == 0) {
                    seq.erase(ps);
                }

                continue;
            }

            if (ps->second > 1) {
                if (seq.count(ps->first<<1)) {
                    seq[ps->first<<1]++;
                } else {
                    seq[ps->first<<1] = 1;
                }

                ps->second-=2;
            }

            if (ps->second < 2) {
                seq.erase(ps);
            }
        }

        if (pn != numero.end()) {
            cout << "-1" << endl;
            continue;
        }

        cout << cortes << endl;
    }
}