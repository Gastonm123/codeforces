#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e5+5;
int abecedario[MAXN][26];

int main() {
    int t;

    cin >> t;

    while (t--) {
        string s, e;

        cin >> s >> e;

        int abecedario_manual[26];
        memset(abecedario_manual, 0, sizeof(abecedario_manual));

        for (int i=s.size()-1; i >= 0; i--) {
            // rellenando el abecedario
            int key = s[i] - 'a';

            abecedario_manual[key] = i+1;
            // cout << i << " " << s[i];
            memcpy(abecedario[i], abecedario_manual, sizeof(abecedario_manual));
        }

        int iteraciones = 0;
        int i = 0;
        bool se_encontro = true;
        for (;i<e.size() && se_encontro;) {
            int pointer = 0;
            se_encontro = false;
            iteraciones++;
            while (pointer < s.size() && i < e.size()) {
                int key = e[i] - 'a';
                int next_pointer = abecedario[pointer][key];
                // cout << "SE ENCONTRO " << e[i] << " EN " << next_pointer << endl;

                if (next_pointer != 0) {
                    pointer = next_pointer;
                    se_encontro = true;
                    i++;
                } else {
                    break;
                }
            }
            // cout << i << endl;
        }

        if (i < e.size()) {
            cout << "-1" << endl;
        } else {
            cout << iteraciones << endl;
        }
    }
}