#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Lasketaan dynaamisesti sallittujen taulukoiden määrä.
 *
 */

const int N = 1e5+2, maxM = 100, M = 1e9+7;

int dp[N][maxM];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long res = 0;

    vector<int> luvut;
    for (int i = 0; i < n; i++) {
        int luku;
        cin >> luku;
        luvut.push_back(luku);
    }

    //dp-taulukon alustus
    if (luvut[0]) { // jos ei nolla
        dp[0][luvut[0]] = 1;
    }
    else { // jos nolla
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        if (luvut[i]) { // jos ei nolla
            dp[i][luvut[i]] += dp[i-1][luvut[i]];
            if (luvut[i] > 1) {
                dp[i][luvut[i]] += dp[i-1][luvut[i]-1];
                dp[i][luvut[i]] %= M;
            }
            if (luvut[i] < m) {
                dp[i][luvut[i]] += dp[i-1][luvut[i]+1];
                dp[i][luvut[i]] %= M;
            }
        }
        else { // jos nolla
            for (int j = 1; j <= m; j++) {
                dp[i][j] += dp[i-1][j];
                if (j > 1) {
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] %= M;
                }
                if (j < m) {
                    dp[i][j] += dp[i-1][j+1];
                    dp[i][j] %= M;
                }
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        res += dp[n-1][i];
        res %= M;
    }

    cout << res;

    return 0;
}