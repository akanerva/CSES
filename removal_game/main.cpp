#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Päivitetään taulukkoon mikä on missäkin tilanteessa optimaalisen pelaamisen
 * tulos kummallekin pelaajalle, mutta todellisuudessa yritetään maksimoida
 * ensimmäisen pelaajan tulos.
 */

const int N = 5e3;
pair<long long, long long> dp[N+1][N+1];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> luvut;
    for (int i = 0; i < n; i++) {
        int luku;
        cin >> luku;
        luvut.push_back(luku);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0, j = k; j < n; j++, i++) {
            if (i == j) {
                dp[i][j].first = luvut[i];
            }
            else {

                if (luvut[i]+dp[i+1][j].second > luvut[j]+dp[i][j-1].second) {
                    dp[i][j].first = luvut[i]+dp[i+1][j].second;
                    dp[i][j].second = dp[i+1][j].first;
                }
                else {
                    dp[i][j].first = luvut[j]+dp[i][j-1].second;
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }
    }
    /*
    //printti
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j].first << "," << dp[i][j].second << " ";
        }
        cout << "\n";
    }
    */


    cout << dp[0][n-1].first;

    return 0;
}