#include <iostream>
#define forn(i, n) for(int i=0;i<n;i++)

using namespace std;

int main() {
    int t;
    cin >> t;

    int pilas[105];
    while (t--) {
        int n, d;
        cin >> n >> d;
        forn (i, n) {
            cin >> pilas[i];
        }

        forn (i, n-1) {
            int j = i+1;
            while (d >= j && pilas[j]) {
                pilas[j]--;
                pilas[0]++;
                d -= j;
            }
        }

        cout << pilas[0] << endl;
    }
}