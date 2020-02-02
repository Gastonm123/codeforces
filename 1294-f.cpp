#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 2e5+5;
vector<int> graph[MAXN];

typedef pair<int, int> ii;
ii farest;

void dfs(int nodo, int prof, int padre) {
    if (prof > farest.first) {
        farest = make_pair(prof, nodo);
    }

    for (int vecino : graph[nodo]) {
        if (vecino == padre){
            continue;
        }

        dfs(vecino, prof+1, nodo);
    }
}

typedef pair<ii, ii> dp;

dp memo[MAXN];

void best_pair(int nodo, int padre) {
    vector<ii> memo_vecinos;
    for (int vecino : graph[nodo]) {
        if (vecino == padre) {
            continue;
        }

        best_pair(vecino, nodo);
        memo_vecinos.push_back(memo[vecino].first);
        memo_vecinos.push_back(memo[vecino].second);
    }

    if (memo_vecinos.empty()) {
        memo[nodo] = make_pair(
            make_pair(1, nodo),
            make_pair(0, 0)
        );
    } else {
        sort(memo_vecinos.begin(), memo_vecinos.end(), greater<ii>());

        ii best = memo_vecinos[0];
        best.first++;

        memo[nodo] = make_pair(
            best,
            memo_vecinos[1]
        );
    }
}

int main() {
    int n;

    cin >> n;

    int copia = n;

    while(copia-- > 1) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    farest = make_pair(0, 0);
    dfs(1, 1, 0);

    best_pair(farest.second, 0);

    dp ans = memo[farest.second];

    if (ans.second.second < 1) {
        // linea
        if (farest.second != n && ans.first.second != n) {
            ans.second.second = n;
        }
        if (farest.second != n-1 && ans.first.second != n-1) {
            ans.second.second = n-1;
        }
        if (farest.second != n-2 && ans.first.second != n-2) {
            ans.second.second = n-2;
        }
    }

    cout << ans.first.first + ans.second.first - 1 << endl;
    cout << farest.second << " " << ans.first.second << " " << ans.second.second << endl; 
}