#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1680
 *
 * lvl1 naiivi: bfs (liian hidas(tosin todnäk sitäkin voisi optimoida ainakin läpäisyyn asti))
 *
 * lvl500 bigboss: dfs dp
 *
 */

const int maxN = 1e5+1;
int dp[maxN];
bool used[maxN];
vector<int> tree[maxN];
int res[maxN];

void dfs(int curr) {
    used[curr] = true;
    for (auto next : tree[curr]) {
        if (!used[next]) dfs(next);
        if (dp[next] && dp[next] >= dp[curr]) {
            dp[curr] = dp[next]+1;
            res[curr] = next;
        }
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

    if (dp[1]) {
        cout << dp[1] << "\n";
        int u = 1;
        while (true) {
            cout << u << " ";
            if (u == n) break;
            u = res[u];
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
    /*
    for (int i = 1; i <= n; ++i) {
        cout << i << " - " << dp[i] << "\n";
    }*/



    return 0;
}