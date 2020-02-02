#include <iostream>
#include <algorithm>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

const int MAXN = 1e6 + 5;
int A[MAXN];

int resolver(int p, int a, int b) {
    if (p < 0) {
        return 0;
    }

    int m = a;
    for (int i = a; i < b; i++) {
        if (A[i]&(1<<p)) {
            m = i;
            break;
        }
    }

    if (a == m || b == m) {
        return resolver(p-1, a, b);
    }

    return (1<<p) + min(resolver(p-1, a, m), resolver(p-1, m, b));
}

int main() {
    int n;
    cin >> n;

    forn(i, n) {
        cin >> A[i];
    }

    sort(A, A+n);
    cout << resolver(29, 0, n) << endl;
}