#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

const int MAXN = 2000;
vector<int> graph[MAXN];
int cantidades[MAXN];

typedef pair<int, int> ii;

bool comp(ii a, ii b) {
    return a.second < b.second;
}

vector<ii> merge(vector<ii> a, vector<ii> b) {
    int tamanio_respuesta = a.size() + b.size();
    vector<ii> ans(tamanio_respuesta);

    int ia = 0;
    int ib = 0;
    forn (i, tamanio_respuesta) {
        if (ia == a.size()) {
            ans[i] = b[ib++];
            continue;
        }

        if (ib == b.size()) {
            ans[i] = a[ia++];
            continue;
        }

        if (a[ia] < b[ib])
            ans[i] = a[ia++];
        else
            ans[i] = b[ib++];
    }


    return ans;
}

vector<ii> descubrir(int nodo) {
    if (graph[nodo].size() == 0) {
        if (cantidades[nodo] > 0) {
            throw "";
        }

        vector<ii> ans;
        ans.push_back(make_pair(1, nodo));

        return ans;
    }

    int vecinos = graph[nodo].size();
    vector<ii> descubrimiento[vecinos];
    vector<ii> merge_list;

    forn (i, vecinos) {
        int vecino = graph[nodo][i];

        vector<ii> descubrimiento = descubrir(vecino);
        
        // merge de los descubrimientos
        merge_list = merge(merge_list, descubrimiento);
    }


    // poner al nodo en la posicion c y mover todo el en c+1, 1
    int c = cantidades[nodo];

    // es imposible la operacion si c > merge_list.size()
    if (c > merge_list.size()) {
        throw "";
    }

    vector<ii> ans(merge_list.begin(), merge_list.begin() + c);

    if (c > 0) {
        int ultimo = ans[ans.size() - 1].first; 
        ans.push_back(make_pair(ultimo+1, nodo));
    } else {
        ans.push_back(make_pair(1, nodo));
    }

    forn (i, merge_list.size()-c) {
        ii el = merge_list[i+c];
        ans.push_back(make_pair(el.first+1, el.second));
    }

    return ans;
}

int main() {
    int n;

    cin >> n;

    int raiz;
    forn (i, n) {
        int p, c;

        cin >> p >> c;

        if (p == 0) {
            raiz = i;
        } else {
            graph[p-1].push_back(i);
        }

        cantidades[i] = c;
    }

    vector<ii> lista;
    try {
        lista = descubrir(raiz);
    } catch (const char* msg) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    sort(lista.begin(), lista.end(), comp);

    forn(i, n) {
        cout << lista[i].first << " ";
    }

    cout << endl;
}