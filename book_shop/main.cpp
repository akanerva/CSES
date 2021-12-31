#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
int dp[N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> kirjat; // {hinta, sivut}
    for (int i = 0; i < n; i++) kirjat.emplace_back(0, 0);
    for (int i = 0; i < n; i++) cin >> kirjat[i].first;
    for (int i = 0; i < n; i++) cin >> kirjat[i].second;

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= kirjat[i].first; j--) {
            dp[j] = max(dp[j], dp[j-kirjat[i].first]+kirjat[i].second);
        }
    }
    cout << dp[x];

    return 0;
}