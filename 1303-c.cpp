#include <iostream>
#include <deque>
#include <set>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

typedef deque<char>::iterator it;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        deque<char> ans;

        ans.push_back(s[0]);
        it pos = ans.begin();
        set<char> existentes;
        existentes.insert(s[0]);
        try {
            forn (i, n-1) {
                char next = s[i+1];

                if (pos != ans.begin() && pos[-1] == next) {
                    pos = pos-1;
                    continue;
                }

                if (pos != (ans.end()-1) && pos[1] == next) {
                    pos = pos+1;
                    continue;
                }

                if (existentes.count(next)) {
                    throw 0;
                }

                if (pos == ans.begin()) {
                    ans.push_front(next);
                    existentes.insert(next);
                    pos = pos-1;
                    continue;
                } 
                
                if (pos == (ans.end()-1)) {
                    ans.push_back(next);
                    existentes.insert(next);
                    pos = pos+1;
                    continue;
                }

                throw 0;
            }
        } catch (int e) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        for (char c : ans) {
            cout << c;
        }

        forn (i, 26) {
            char letra = char('a' + i);
            if (existentes.count(letra))
                continue;
            
            cout << letra;
        }
        cout << endl;
    }
}