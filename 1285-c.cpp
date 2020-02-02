#include <iostream>
#include <utility>
#include <vector>
#define forn(i, n ) for(int i=0; i<n; i++)
#define forr(i, n ) for(int i=1; i<n; i++)

using namespace std;

int MAXROOTN = 1e7 + 5;
// bool criba[MAXROOTN];
typedef long long ll;

long long gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    long long n;

    cin >> n;

    // vector<int> factores_n;

    // criba[0] = true;
    // criba[1] = true;

    long long minimo = 1e13;
    pair<long long, long long> pareja;
    forr (i, MAXROOTN) {
        if (n % i == 0) {
            long long candidato = n / i;

            if (lcm(i, candidato) == n) {
                long long valor_pareja = max(candidato, ll(i)); 
                if (valor_pareja < minimo) {
                    pareja = make_pair(candidato, i);
                    minimo = valor_pareja;
                }
            }
        }
    }

    cout << pareja.first << " " << pareja.second << endl; 
}