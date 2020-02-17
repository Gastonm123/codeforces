#include <iostream>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        bool uno = false;
        int n = s.size();
        int ans = 0;
        int temp = 0;

        forn (i, n) {
            if (s[i] == '1') {
                if (uno) {
                    ans += temp;
                } 
                uno = true;
                temp = 0;
            } else if (uno) {
                temp++;
            }

        }

        cout << ans << endl;
    }
}