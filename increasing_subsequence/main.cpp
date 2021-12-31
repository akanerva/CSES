#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Tehty kkkk:n esimerkin mukaisesti.
 * n*log*n -aikakompleksinen dynaamisesti laskettu ratkaisu.
 *
 */

int dp[200001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    //int dp[n];
    dp[0] = 1;

    vector<int> luvut;
    for (int i = 0; i < n; i++) {
        int luku;
        cin >> luku;
        luvut.push_back(luku);
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
        int msf = 1;
        for (int j = 0; j < i; j++) {
            if (luvut[i] > luvut[j]) msf = max(dp[j]+1, msf);
        }
        dp[i] = msf;
        res = max(res, msf);
    }
    /*
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    */
    cout << res;


    return 0;
}