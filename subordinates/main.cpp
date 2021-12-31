#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Tehdään suunnattu verkko jonka juurena on solmu 1.
 * Ajetaan dfs juuresta ja lasketaan dynaamisesti alipuiden koot.
 */

const int maxN = 2e5+1;
int cnt[maxN];
vector<int> tree[maxN];

void dfs(int node) {
    cnt[node] = 1;
    for (auto next : tree[node]) {
        dfs(next);
        cnt[node] += cnt[next];
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int e;
        cin >> e;
        tree[e].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << cnt[i]-1 << " ";
    }


    return 0;
}