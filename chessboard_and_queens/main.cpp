#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Käytetään peruuttavaa hakua. Ei aseteta kuningattaria *-ruutuihin.
 */

vector<string> lauta;
int c = 0;
const int n = 8;
bool r1[n];
bool r2[2*n];
bool r3[2*n];

//peruuttava haku
void haku(int y) {
    if (y == n) {
        c++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (r1[x] || r2[x+y] || r3[x-y+n-1] || lauta[y][x] == '*') continue;
        r1[x] = r2[x+y] = r3[x-y+n-1] = true;
        haku(y+1);
        r1[x] = r2[x+y] = r3[x-y+n-1] = false;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        lauta.push_back(input);
    }

    haku(0);

    cout << c;
    return 0;
}