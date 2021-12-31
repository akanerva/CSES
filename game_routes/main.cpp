#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1681
 *
 * dfs dp?
 *
 */

const int maxN = 1e5+1;
const int M = 1e9+7;
vector<int> tree[maxN];
int dp[maxN];
bool used[maxN];

void dfs(int curr) {
    used[curr] = true;
    for (auto next : tree[curr]) {
        if (!used[next]) dfs(next);
        dp[curr] += dp[next];
        dp[curr] %= M;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
    }

    dp[n] = 1;

    dfs(1);

    cout << dp[1];

    return 0;
}