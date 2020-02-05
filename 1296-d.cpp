#include <iostream>
#include <algorithm>
#include <vector>

#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;
int n, a, b, k;

void resolver(vector<int> m) {
    int turno = a + b;

    vector<int> lost_rounds;
    int puntos = 0;

    forn (i, n) {
        int mod = m[i] % turno;
        mod = (mod == 0 ? turno : mod);
        mod -= a;

        if (mod <= 0) {
            puntos++;
        } else {
            lost_rounds.push_back(mod);
        }
    }

    // cout << puntos << endl;

    sort(lost_rounds.begin(), lost_rounds.end());
    forn (i, lost_rounds.size()) {
        int vida = lost_rounds[i];
        while (k > 0 && vida > 0) {
            // cout << vida << endl;
            vida -= a;
            k--;
        }

        if (vida <= 0) {
            puntos++;
        }
    }

    cout << puntos << endl;
}

int main() {
    cin >> n >> a >> b >> k;

    vector<int> m(n);
    forn (i, n) {
        cin >> m[i];
    }

    resolver(m);
}