#include <iostream>

using namespace std;

const int MAXN = 4e5+5;
int modulos[MAXN];

int main() {
    int q, x;
    cin >> q >> x;

    int actual = 0;
    while (q--) {
        // los modulos se van a limitar a x
        int numero;
        cin >> numero;
        modulos[numero % x]++;

        while(true) {
            int key = actual % x;

            if (modulos[key] == 0) {
                break;
            } else {
                actual++;
                modulos[key]--;
            }
        }

        cout << actual << endl;
    }
}