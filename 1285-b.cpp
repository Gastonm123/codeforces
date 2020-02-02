#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        long long suma = 0;
        long long maximo = 0;
        int elementos[n];
        for (int i = 0; i < n; i++) {
            int el; cin >> elementos[i];
        }

        for (int  i=0; i<n; i++) {
            suma += elementos[i];
            if (i < n-1) {
                maximo = max(maximo, suma);
            }

            if (suma <= 0) {
                break;
            }
        }
        if (suma > 0 && suma > maximo) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}