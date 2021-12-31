#include <bits/stdc++.h>

using namespace std;

const int M = 1e9+7, N = 1e6;
long long dp[N+1];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(6, i); ++j) {
            dp[i] = (dp[i] + dp[i-j]) % M;
        }
    }

    cout << dp[n];

    return 0;
}