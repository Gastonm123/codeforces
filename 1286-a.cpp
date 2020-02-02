#include <iostream>
#include <tuple>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

const int MAXN = 105;
int numeros[MAXN];
int n;

int DP[MAXN][MAXN][MAXN][2];

int complejidad(int a, int b) {
    return (a != b);
}


int minc(int pos, int pares, int impares, int yo) {
    if (pares < 0 || impares < 0) {
        return n;
    }

    if (pos == n-1) {
        return 0;
    }

    if (DP[pos][pares][impares][yo] != -1) {
        return DP[pos][pares][impares][yo];
    }

    if (numeros[pos+1] != 0) {
        int key_siguiente = numeros[pos+1] % 2;
        int resultado = minc(pos+1, pares, impares, key_siguiente) + complejidad(yo, key_siguiente);

        return DP[pos][pares][impares][yo] = resultado;
    }

    int resultado1 = minc(pos+1, pares-1, impares, 0) + complejidad(yo, 0);
    int resultado2 = minc(pos+1, pares, impares-1, 1) + complejidad(yo, 1);

    if (resultado1 < resultado2) {
        return DP[pos][pares][impares][yo] = resultado1;
    } else {
        return DP[pos][pares][impares][yo] = resultado2;
    }
}

int main() {
    cin >> n;

    int paridad = n % 2;
    int impares = n / 2 + (paridad == 1);
    int pares   = n / 2;

    forn(i, n) {
        cin >> numeros[i];

        if (numeros[i] != 0) {
            if (numeros[i] % 2 == 1) {
                impares--;
            } else {
                pares--;
            }
        }
    }

    forn (i, MAXN) forn (j, MAXN) forn(k, MAXN) DP[i][j][k][0] = -1, DP[i][j][k][1] = -1;

    int resultado;

    if (numeros[0] != 0) {
        resultado = minc(0, pares, impares, numeros[0]%2);    
    } else {
        int resultado1 = minc(0, pares-1, impares, 0);
        int resultado2 = minc(0, pares, impares-1, 1);

        resultado = min(resultado1, resultado2 );
    }

    cout << resultado << endl;
}