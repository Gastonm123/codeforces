#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b;

        cin >> a >> b;

        long long resultado = 0;
        int valor_b = 10; b++;
        while (valor_b <= b) resultado += a, valor_b *= 10;

        cout << resultado << endl;
    }
}