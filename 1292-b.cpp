#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

// const float omega = 1e-5;

struct dot {
    long long x, y;

    long long operator - (dot a) {
        return abs(this->x - a.x) + abs(this->y - a.y);
    }

    bool operator == (dot a) {
        return (a.x == this->x && a.y == this->y);
    }
};

int xd(vector<dot> alcanzables, long long t, dot yo) {
    int visitados = 0;
    dot actual = yo;
    do {
        if (alcanzables.empty()) {
            break;
        }

        dot a_visitar = alcanzables[0];
        int pos_a_visitar = 0;
        long long minimo = a_visitar - actual;

        for (int i=1; i<alcanzables.size(); i++) {
            dot a = alcanzables[i];
            long long dist_a = a - actual;
            if (minimo > dist_a) {
                minimo = dist_a;
                pos_a_visitar = i;
                a_visitar = a;
            }
        }

        // cout << a_visitar.x << " " << a_visitar.y << " " << minimo << endl;
        // cout << t << endl;

        if (t >= minimo) {
            alcanzables.erase(alcanzables.begin() + pos_a_visitar);
            t -= minimo;
            actual = a_visitar;
            visitados++;
        } else {
            break;
        }
    } while(1);

    return visitados;
}

int main() {
    dot i;
    dot a, b;
    cin >> i.x >> i.y >> a.x >> a.y >> b.x >> b.y;

    dot yo; long long t;
    cin >> yo.x >> yo.y >> t;

    dot previous = i;
    vector<dot> alcanzables;
    do {
        dot next = {
            previous.x * a.x + b.x,
            previous.y * a.y + b.y
        };

        long long dist_next = next - yo;
        long long dist_prev = previous - yo;

        bool dentro_area = (t >= dist_next);
        bool dentro_area_prev = (t >= dist_prev); 

        if (t >= dist_prev) {
            alcanzables.push_back(previous);
        }

        previous = next;

        if (!dentro_area && dist_next > dist_prev) 
            break;
    } while(1);

    int maximo = 0;
    for (int i = 0; i < alcanzables.size(); i++) {
        dot a = alcanzables[i];
        long long dist = a - yo;
        long long t_desde_a = t - dist;
        vector<dot> copia_alcanzables = alcanzables;

        copia_alcanzables.erase(copia_alcanzables.begin() + i);

        int jaja = xd(copia_alcanzables, t_desde_a, a) + 1;

        maximo = max(maximo, jaja);
    }

    cout << maximo << endl;
}