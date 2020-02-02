#include <iostream>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

const int MAXN = 1e5 + 5;
bool calabozo[2][MAXN];
int padre[2][MAXN];

int dy[] = {1, 1, 1};
int dx[] = {-1, 0, 1};
int n;
int tamanio = 0;

void unir (int x, int y, int mod) {
    forn (i, 3) {
        int nx = x+i-1;
        if (nx < 0 || nx > n-1) {
            continue;
        }

        if (calabozo[!y][nx] && padre[!y][nx] == 0) {
            tamanio++;
        }

        padre[!y][nx] += mod;
        if (calabozo[!y][nx] && padre[!y][nx] == 0) {
            tamanio--;
        }
    }
}

int main() {
    int q;
    cin >> n >> q;

    int tamanio_grupo = 0;
    while(q--) {
        int x, y;
        cin >> y >> x;

        y--; x--;

        if (y) {
            if (calabozo[y][x]) {
                unir(x, y, -1);
            } else {
                unir(x, y, 1);
            }
        } else {
            if (calabozo[y][x] && padre[y][x] > 0) {
                tamanio--;
            } else if (padre[y][x] > 0) {
                tamanio++;
            }
        }

        calabozo[y][x] = !calabozo[y][x];
        
        cout << (tamanio == 0 ? "Yes" : "No") << endl;
    }
}