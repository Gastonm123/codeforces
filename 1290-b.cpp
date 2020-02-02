#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#include <cmath>

#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

int block;
typedef pair<int, int> ii;

struct dp {
    int first;
    int second;
    int origen;
    bool ans;
};

bool compare(dp a, dp b) {
    if (a.first / block != b.first / block)
        return a.first < b.first;

    return a.second < b.second;
}

bool comp(dp a, dp b) {
    return a.origen < b.origen;
}


int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    block = (int)sqrt(s.size());
    vector<dp> querys(q);
    forn(i, q) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        querys[i] = {a,b,i,0};
    }

    sort(querys.begin(), querys.end(), compare);

    int current_l = 0;
    int current_r = 0;
    int current_unique = 0;
    int current_dicc[26];
    memset(current_dicc, 0, sizeof(current_dicc));

    function<void(char,int)> contar_aparicion = [&](char a, int modificador){
        int key = a - 'a';

        if (current_dicc[key] == 0)
            current_unique++;

        current_dicc[key] += modificador;

        if (current_dicc[key] == 0) 
            current_unique--;
            //probable bug no tiene en cuenta modificador y numeros negativos
    };

    
    // vector<bool> ans(q);
    forn (i, q) {
        int L = querys[i].first, R = querys[i].second;

        // cout << L << " " << R << endl;
        if (s[L] != s[R] || L==R) {
            querys[i].ans = 1;
            continue;
        }

        while (current_l < L) {
            contar_aparicion(s[current_l], -1);
            current_l++;
        }

        while (current_l > L) {
            contar_aparicion(s[current_l-1], 1);
            current_l--;
        }

        while (current_r <= R) {
            contar_aparicion(s[current_r], 1);
            current_r++;
        }

        while (current_r > R+1) {
            contar_aparicion(s[current_r-1], -1);
            current_r--;
        }

        // cout << current_unique << endl;

        querys[i].ans = (current_unique >= 3);
    }

    sort(querys.begin(), querys.end(), comp);
    forn (i, q) cout << (querys[i].ans ? "YES" : "NO") << endl;
}