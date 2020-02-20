#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define forn(i, n) for(int i=0; i<n; i++)
#define all(x) begin(x),end(x)

using namespace std;

unordered_map<string, int> mapa;

int main() {
    int n, m;
    cin >> n >> m;

    string palabras[n];
    forn (i, n) {
        cin >> palabras[i];
    }

    vector<string> ans;
    forn (i, n) {
        string pal = palabras[i];
        string rev = pal;
        reverse(all(rev));

        if (mapa.count(rev)) {
            mapa[rev]--;
            ans.push_back(rev);
            if (mapa[rev] == 0) {
                mapa.erase(rev);
            }
        } else if (mapa.count(pal)) {
            mapa[pal]++;
        } else {
            mapa[pal] = 1;
        }
    }

    string output = "";
    for (string s : ans) {
        output += s;
    }

    for (auto e : mapa) {
        string s = e.first;
        string r = s;
        reverse(all(r));

        if (s == r) {
            output += s;
            break;
        }
    }

    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        string s = *it;
        reverse(all(s));
        output += s;
    }

    cout << output.size() << endl;
    cout << output << endl;
}