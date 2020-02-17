#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, g, b;
        cin >> n >> g >> b;

        long long dias = 0;
        long long buenas = ceil(float(n)/2);
        long long malas = n - buenas;

        long long periodos = 0;
        long long suma = g + b;

        long long dias_b = (malas / b) * suma;
        dias_b += (malas%b > 0 ? g+malas%b : 0);

        if (n <= dias_b) {
            cout << n << endl;
        } else {
            dias += (malas%b > 0 ? (malas/b+1) * suma : dias_b);
            n -= dias_b;

            long long dias_n;
            if (n % g == 0) {
                dias_n = (n / g - 1) * suma + g;
            } else {
                dias_n = (n / g) * suma + n % g;
            }

            cout << dias + dias_n << endl;
        }
    }
}