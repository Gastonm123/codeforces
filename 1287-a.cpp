#include <iostream>
#define forn(i, k) for(int i =0; i<k; i++)

using namespace std;

int main() {
    int k;
    
    cin >> k;

    forn (i, k) {
        int largo;
        string fila;

        cin >> largo >> fila;

        int iteracion = 0;
        bool igual;
        do {
            igual = true;
            
            char pointer = fila[0];
            forn (j, largo-1) {
                char next = fila[j+1];

                if (pointer == 'A' && next == 'P') {
                    fila[j+1] = 'A';
                    igual = false;
                } 

                pointer = next;
            }

            if (!igual) {
                iteracion++;
            }
        } while (!igual);

        cout << iteracion << endl;
    }

}