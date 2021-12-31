#include <bits/stdc++.h>

using namespace std;

int dp[501][501];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i ^ j) { // XOR
                dp[i][j] = 1e9;
            }
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }

    cout << dp[a][b];

    return 0;
}