#include <iostream>
#include <vector>
#include <cstring>
#define forn(i ,n ) for(int i=0; i<n; i++)
#define limpiar(a)     memset(a, 0, sizeof(a))

typedef long long ll;

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int diccionario[26];
    limpiar(diccionario);

    forn (i, n) {
        int key = s[i] - 'a';

        diccionario[key]++;
    }

    long long maximo = 1;
    forn (i, 26) {
        vector<int> copia_diccionario(diccionario, diccionario+26);
        long long sumas[26];
        limpiar(sumas);

        forn (j, n) {
            int key = s[j] - 'a';
            copia_diccionario[key]--;

            if (key == i) {
                forn (k, 26) {
                    sumas[k] += copia_diccionario[k];
                }
            }
        }

        forn (j, 26) {
            maximo = max(maximo, sumas[j]);
        }
    }

    forn (i, 26) {
        maximo = max(maximo, ll(diccionario[i]));
    }

    cout << maximo << endl;
}