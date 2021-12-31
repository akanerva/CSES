#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Tarkoituksena ajaa dfs ja tarkastaa onko verkko kaksijakoinen.
 */

const int maxN = 1e5+2;
vector<int> tree[maxN];
int used[maxN]; // 0=unvisited, 1=red, 2=blue

bool dfs(int node, int prev) {
    if (used[prev] == 0 || used[prev] == 2)  {
        used[node] = 1;
    }
    else {
        used[node] = 2;
    }
    for (auto next : tree[node]) {
        if (used[next] == used[node]) {
            return false;
        }
        if (!used[next]) {
            if (!dfs(next, node)) return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i] && !dfs(i,0)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << used[i] << " ";
    }

    return 0;
}