#include <bits/stdc++.h>

using namespace std;

const int maxN = 501;
long long d[maxN][maxN]; //etäisyystaulukko
long long v[maxN][maxN]; //vieruslista
/**
 * akanerva
 *
 * Floyd-Warshallin algoritmi kkkk:sta.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i) {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        if (!v[a][b]) {
            v[a][b] = c;
            v[b][a] = c;
        }
        else {
            v[a][b] = min(v[a][b], c);
            v[b][a] = min(v[b][a], c);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i==j) d[i][j] = 0;
            else if (v[i][j]) d[i][j] = v[i][j];
            else d[i][j] = LLONG_MAX;
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (d[i][k] == LLONG_MAX || d[k][j] == LLONG_MAX) {
                    continue;
                }
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int a,b;
        cin >> a >> b;
        if (d[a][b] == LLONG_MAX) cout << -1;
        else cout << d[a][b];
        cout << "\n";
    }


    return 0;
}