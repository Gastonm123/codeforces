#include <iostream>
#include <algorithm>
#include <vector>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

int main() {
    int n;
    cin >> n;

    int numeros[n];
    forn (i, n) {
        cin >> numeros[i];
    }

    vector<int> active(n+1, 0);
    int j = 1;

    forn (i, n) {
        auto iter = lower_bound(active.begin(), active.begin()+j, numeros[i], [](int a, int b){
            return a < b;
        });

        iter[0] = numeros[i];

        if (iter == active.begin()+j) {
            j++;
        }
    }

    cout << j << endl;
    forn (i, j) {
        cout << active[i] << endl;
    }
}