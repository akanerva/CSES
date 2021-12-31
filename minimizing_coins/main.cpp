#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Lasketaan dynaamisesti pienin kolikkojen määrä.
 */

int n, x;
int d[1000002];
vector<int> kolikot;

int f(int x) {
    if (x == 0) return 0;
    if (x < 0) return 1e9;
    if (d[x]) return d[x];
    int u = 1e9;
    for (int i = 0; i < n; i++) {
        u = min(u, f(x-kolikot[i])+1);
    }
    d[x] = u;
    return d[x];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int kolikko;
        cin >> kolikko;
        kolikot.push_back(kolikko);
    }

    int res = f(x);
    if (res == 1e9) res = -1;
    cout << res;

    return 0;
}