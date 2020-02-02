#include <iostream>
#include <cmath>

using namespace std;

bool entra(int n, int d, int x) {
    int d_optimizado = ceil(float(d)/(x+1));
    
    return (d_optimizado + x) <= n;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, d;
        cin >> n >> d;

        // busqueda binaria de un valor para x que haga que entre en tiempo d
        int a = -1;
        int b = n;
        while(b>a+1) {
            int m = (a+b) / 2;

            if (entra(n, d, m)) {
                a = m;
            } else {
                b = m;
            }
        }

        if (a == -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}