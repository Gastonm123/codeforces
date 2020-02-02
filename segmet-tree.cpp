#include <iostream>
#include <vector>
#define forn(i, a, n) for(int i=a; i<n; i++)
#define forr(i, a, n) for(int i=n; i>=a; i--)

using namespace std;

const int MOD = 1e9+7;

class st {
public:
    vector<int> valores;

    st(int n) {
        int tamanio = 1;
        while(n>0) n<<=1, tamanio >>=1;

        valores.resize(tamanio*2+1);

        forr (i, 1, tamanio*2) {
            if (i < tamanio) {
                valores[i] = valores[i*2] + valores[i*2+1];
            } else {
                valores[i] = 1;
            }
        }
    }
};

int main() {
    st* arbolito = new st(1);

    forn (i, 0, arbolito->valores.size()) {
        cout << arbolito->valores[i] << endl;
    }
}