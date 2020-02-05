#include <iostream>
#include <vector>

#define forn(i, n) for(int i=0; i<n; i++)
using namespace std;

void resolver(int n, string s) {
    vector<bool> colores_ordenados(n);
    vector<bool> colores(n);
    forn (i, n) {
        if (i > 0 && s[i-1] > s[i]) {
            colores[i] = !colores_ordenados[i-1];
            colores_ordenados[i] = colores[i];
        }
        
        for (int j=i; j>0; j--) {
            if (s[j-1] > s[j]) {
                if (colores_ordenados[j] != colores_ordenados[j-1]) {
                    swap(colores_ordenados[j], colores_ordenados[j-1]);
                    swap(s[j], s[j-1]);
                }
                else {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
    forn (i, n) cout << colores[i];
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    resolver(n, s);
}