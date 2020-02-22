#include <iostream>
#include <vector>
#define forn(i,n) for(int i=0; i<n; i++)

using namespace std;

const int MAXN = 1e5+5;
int bit[MAXN];
int n;

void update(int ind, int val) {
    for (ind++; ind<=n; ind += (ind & -ind)) {
        bit[ind] = max(val, bit[ind]);
    }
}

int query(int ind) {
    int ans = 0;
    for (ind++; ind > 0; ind -= (ind & -ind)) {
        ans = max(ans, bit[ind]);
    }
    return ans;
}


int main() {
    vector<int> a; a.reserve(10);
    a.push_back(10);
    cout << a.capacity() << endl; exit(0);
    cin >> n;

    forn (i, n) {
        int a;
        cin >> a;

        update(i, a);
    }

    int q;
    cin >> q;
    
    forn (i, q) {
        int b;
        cin >> b;

        cout << query(b-1) << endl; 
    }
}