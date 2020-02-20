#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#define forn(i, n) for(int i=0; i<n; i++)
 
using namespace std;
 
const int MAXN = 2e5+5;
vector<int> graph[MAXN];
set<int> especiales;
int profundidades[MAXN];
 
void dfs(int nodo, int prof) {
    profundidades[nodo] = prof;
    for (int v : graph[nodo]) {
        if (profundidades[v] == -1) {
            dfs(v, prof+1);
        }
    }
}
 
set<int> criticos;
 
void dfs_alternado(int nodo) {
    criticos.insert(nodo);
    for (int v : graph[nodo]) {
        if (profundidades[v] == profundidades[nodo]-1) {
            dfs_alternado(v);
        }
    }
}
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
 
    forn (i, k) {
        int especial;
        cin >> especial;
        especial--;
        especiales.insert(especial);
    }
 
    bool especiales_conectados = false;
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
 
        if (especiales.count(a) && especiales.count(b))
            especiales_conectados = true;
    }
 
    memset(profundidades, -1, sizeof(profundidades));
    dfs(0, 0);
 
    if (especiales_conectados) {
        cout << profundidades[n-1] << endl;
        exit(0);
    }
 
    dfs_alternado(n-1);
 
    // vector<int> no_criticos;
    int no_criticos = 0;
    for (int especial : especiales) {
        if (criticos.count(especial) == 0)
            no_criticos++;
    }
 
    if (no_criticos > 0) {
        cout << profundidades[n-1] << endl;
    } else {
        cout << profundidades[n-1]-1 << endl;
    }
}