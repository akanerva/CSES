#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1192/
 *
 * Suoritetaan tulvatäyttö aina kun kohdataan läpikäymätön
 * huoneen ruutu. Maalataan mustaksi (=läpikäydyksi) loput huoneen ruuduista
 * tulvatäytöllä.
 */

const int maxN = 1001;
int n, m;
bool grid[maxN][maxN]; //seinät ja läpikäydyt true, muuten false

void tulvataytto(int i, int j) {
    grid[i][j] = true;
    if (i > 0 && !grid[i-1][j]) {
        tulvataytto(i-1, j);
    }
    if (j > 0 && !grid[i][j-1]) {
        tulvataytto(i, j-1);
    }
    if (i < n-1 && !grid[i+1][j]) {
        tulvataytto(i+1, j);
    }
    if (j < m-1 && !grid[i][j+1]) {
        tulvataytto(i, j+1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        string rivi;
        cin >> rivi;
        for (int j = 0; j < m; j++) {
            if (rivi[j] == '#') {
                grid[i][j] = true;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!grid[i][j]) {
                res++;
                tulvataytto(i, j);
            }
        }
    }

    cout << res;

    return 0;
}