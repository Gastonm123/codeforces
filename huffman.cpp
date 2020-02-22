#include <bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define limpiar(a) memset(a, 0, sizeof(a))
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef pair<int,int> ii;

bool comp(ii a, ii b) {
    return a.se < b.se;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    int letras[26];
    limpiar(letras);

    forn (i, n) {
        letras[s[i]-'a']++;
    }

    set<ii> left; 
    tuple<int,int,char> tree[2*n];
    int j = 0;

    forn (i, 26) {
        if (letras[i] > 0) {
            tree[j] = make_tuple(
                -1,
                -1,
                char('a' + i)
            );
            left.insert(mp(letras[i], j));
            j++;
        }
    }

    while (left.size() > 1) {
        auto c = left.begin();
        auto d = left.begin(); d++;

        auto a= *c, b= *d;
        // cuando el numero de apariciones sea igual, el orden del set
        // va a dictar que b tenga un indice j mayor y por tanto que vaya a la izquierda
        // esto no es bueno por que va a hacer que los caminos a nodos internos
        // sea mas corto y el camino a las hojas mas largo
        if (a.fi == b.fi)
            swap(a,b);

        tree[j] = make_tuple(
            b.se,
            a.se,
            ' '
        );
        left.insert(mp(a.fi + b.fi, j));
        left.erase(left.begin());
        left.erase(left.begin());
        j++;
    }

    stack<pair<int,int> > st;
    st.push(mp(j-1, 0));

    while (st.size()) {
        auto nodo = st.top();
        st.pop();

        auto v = tree[nodo.fi];
        if (get<0>(v) == -1) {
            cout << get<2>(v) << " " << nodo.se << endl;
            continue;
        }

        int codigo = nodo.se<<1;

        st.push(mp(get<0>(v), codigo));
        st.push(mp(get<1>(v), codigo|1));
    }
}