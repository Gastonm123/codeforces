#include <iostream>

using namespace std;

class trie {
public:
    trie* next[26];

    trie() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }

    void insert(string a) {
        trie* actual = this;

        for (char c : a) {
            int key = c - 'A';
            if (actual->next[key] == nullptr) {
                actual->next[key] = new trie;
            } 
            actual = actual->next[key];
        }
    }
};

char siguiente(char a, char b) {
    if (a == b) {
        return a;
    }

    if (a > b) {
        swap(a, b);
    }

    if (a == 'E') {
        if (b == 'S') {
            return 'T';
        } else {
            return 'S';
        }
    } else {
        return 'E';
    }
}

int main() {
    trie* arbol = new trie;
    
    int n, l;

    cin >> n >> l;

    string strings[n];

    for(int i=0; i < n; i++) {
        string nstring;
        cin >> nstring;

        strings[i] = nstring;
        arbol->insert(nstring);
    }

    int parejas = 0; 
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            bool pareja = false;
            trie* actual = arbol;

            for (int k=0; k<l; k++) {
                char c1 = strings[i][k];
                char c2 = strings[j][k]; 
                char key_siguiente = siguiente(c1, c2) - 'A';

                if (actual->next[key_siguiente] != nullptr) {
                    if (k == l-1) {
                        parejas++;
                    }
                    
                    actual = actual->next[key_siguiente];
                } else {
                    break;
                }
            }
        }
    }

    cout << parejas / 3 << endl;
}