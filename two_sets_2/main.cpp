#include <bits/stdc++.h>

using namespace std;

const int M = 1e9+7, maxN = 500;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long maxSum = n*(n+1)/2;
    if (maxSum & 1) { // jos pariton
        cout << 0;
        return 0;
    }

    maxSum /= 2;
    long long dp[maxN*(maxN+1)/2 +1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i*(i+1)/2; j >= i; j--) {
            dp[j] = (dp[j]+dp[j-i]) % M;
        }
    }

    cout << dp[maxSum]*((M+1)/2) % M;
    

    return 0;
}