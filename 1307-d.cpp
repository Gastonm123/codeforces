#include <iostream>
#define forr(i, a, n) for(int i = n; i >= a; i--)
#define fi first
#define se second
#include <algorithm>
#define all(x) std::begin(x),std::end(x)
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
#define forn(i, n) for(int i=0;i<n;i++)
#define limpiar(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int profundidades[MAXN];
int dist_0[MAXN];
int dist_n[MAXN];

void dfs(int nodo, int prof) {
    queue<pair<int, int> > cola;
    cola.push(make_pair(nodo, 0));
    while (cola.size()) {
        nodo = cola.front().first;
        prof = cola.front().second;
        cola.pop();

        profundidades[nodo] = prof;
        for (int v : graph[nodo]) {
            if (profundidades[v] == -1) {
                profundidades[v] = 0;
                cola.push(make_pair(v, prof+1));
            }
        }
    }
}

struct segtree {
    int size;
    vector<pair<int, int> > arr;
    vector<pair<int, int> > lazy;

    segtree(int n) {
        int copia = n;
        size = 1;

        while(copia > 1) {copia>>=1; size<<=1;}    

        if (size < n) {
            size <<= 1;
        }

        arr.resize(2*size, make_pair(0,0));
        // lazy.resize(size);
    }
    
    pair<int, int> query(int a, int b, int nodo=1, int l=0, int r=0) {
        if (nodo == 1) {
            r = size-1;
        }

        if (a > r || b < l) {
            return make_pair(0,0);
        }

        if (l >= a && r <= b) {
            return arr[nodo];
        }

        int m = (l + r) / 2;

        auto lc = query(a, b, nodo<<1, l, m);
        auto rc = query(a, b, nodo<<1|1, m+1, r);

        return make_pair(max(lc.fi, rc.fi), max(lc.se, rc.se));
    }
};

int bit[MAXN];
int k;

void update(int ind, int val) {
    for (ind++; ind<=k; ind += (ind & -ind)) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m >> k;

    vector<int> nodos_especiales(k);
    forn (i, k) {
        int especial;
        cin >> especial;

        nodos_especiales[i] = especial-1;
    }

    forn (i, m) {
        int a, b;
        cin >> a >> b;

        a--, b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    limpiar(profundidades, -1);
    dfs(0, 0);

    memcpy(dist_0, profundidades, sizeof(profundidades));

    limpiar(profundidades, -1);
    dfs(n-1, 0);

    memcpy(dist_n, profundidades, sizeof(profundidades));

    vector<pair<int,int> > X(k);
    forn (i, k) {
        int nodo = nodos_especiales[i];

        X[i] = make_pair(- dist_0[nodo] + dist_n[nodo], nodo);
    }

    sort(all(X));

    segtree st(k);
    
    forn (i, k) {
        int nodo = X[i].se;

        update(i, dist_n[nodo]);
        // int nodo_arbol = st.size + i;

        // st.arr[nodo_arbol] = make_pair(dist_0[nodo], dist_n[nodo]);
        // for (nodo_arbol;nodo_arbol>0;nodo_arbol>>=1) {
        //     st.arr[nodo_arbol>>1] = make_pair(
        //         max(st.arr[nodo_arbol].fi, st.arr[nodo_arbol^1].fi),
        //         max(st.arr[nodo_arbol].se, st.arr[nodo_arbol^1].se)
        //     );
        // }
    }

    int maximo = 0;
    forr (i, 1, k-1) {
        int nodo = X[i].se;

        // int eleccion = st.query(i+1, k-1).se;
        int eleccion = query(i-1);

        maximo = max(maximo, eleccion+1+dist_0[nodo]);
    }

    cout << min(dist_0[n-1], maximo) << endl;
}