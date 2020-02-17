#include <iostream>
#include <vector>
#include <cmath>
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

double omega = 1e-5;

struct point {
    double x, y;

    double dot(point other) {
        double ans = x * other.x + y * other.y;
        return ans;
    }

    double cross(point other) {
        double ans = x * other.y - y * other.x;
        return ans;  
    }

    double mod() {
        double suma = x*x + y*y; 
        return sqrt(suma);
    }

    point operator+ (point other) {
        return {x+other.x, y+other.y};
    }

    point operator- (point other) {
        return {x-other.x, y-other.y};
    }

    point operator/ (double v) {
        return {x/v, y/v};
    }

    point operator* (double v) {
        return {x*v, y*v};
    }
};

typedef vector<point>::iterator it;

bool iguales(double a, double b) {
    return abs(a-b) < omega;
}

int main() {
    int n;
    cin >> n;

    vector<point> puntos(n);
    forn (i, n) {
        point x;
        cin >> x.x >> x.y;

        puntos[i] = x;
    }

    if (n % 2) {
        cout << "NO" << endl;
        exit(0);
    }

    int m = n / 2;

    forn (i, m-1) {
        if (puntos[i+1].x - puntos[i].x != puntos[i+m].x - puntos[i+m+1].x ||
            puntos[i+1].y - puntos[i].y != puntos[i+m].y - puntos[i+m+1].y) {
            cout << "NO" << endl;
            exit(0);
        }
    }

    cout << "YES" << endl;
    exit(0);
}