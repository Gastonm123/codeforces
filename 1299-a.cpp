#include <iostream>
#include <cstring>
#include <algorithm>
#define forn(i, n) for (int i=0; i<n; i++)

using namespace std;

const int MAXN = 1e5+5;
int numeros[MAXN];

int main() {
    int n;
    cin >> n;

    bool apariciones[32];
    memset(apariciones, 0, sizeof(apariciones));

    int maximo = 0;
    int pos_maximo;
    int a = 0;
    forn (i, n) {
        cin >> numeros[i];

        forn (bit, 32) {
            if (!(numeros[i]>>bit & 1))
                continue;
                
            if (apariciones[bit]) {
                if (a>>bit & 1) 
                    a ^= (1<<bit);

                continue;
            }

            apariciones[bit] = true;
            a |= (1<<bit);
        }
    }

    forn (i, n) {
        int match = numeros[i] & a;
        if (maximo < match) {
            maximo = match;
            pos_maximo = i;
        }
    }

    swap(numeros[0], numeros[pos_maximo]);

    // maximo = numeros[pos_maximo];
    // numeros[pos_maximo] = 0;

    // sort(numeros, numeros+n, greater<int>());

    // cout << maximo << " ";
    forn (i, n) {
        cout << numeros[i] << " ";
    }
    cout << endl;
}