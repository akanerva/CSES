#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1666
 *
 * Ajetaan dfs jokaisesta nodesta jossa ei olla käyty,
 * ja lisätään aloitusnode vectoriin. Näin saadaan joukkojen
 * määrä selville ja yksi node niistä.
 * Lopuksi vedetään jokaisen joukon välille tie.
 */

const int maxN = 1e5+1;
vector<int> tree[maxN];
int visited[maxN];

void dfs(int node) {
    visited[node] = 1;
    for (auto next : tree[node]) {
        if (visited[next]) continue;
        dfs(next);
    }
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

    vector<int> joukot;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        joukot.push_back(i);
        dfs(i);
    }

    cout << (int)joukot.size()-1 << "\n";
    for (int i = 1; i < (int)joukot.size(); i++) {
        cout << joukot[i-1] << " " << joukot[i] << "\n";
    }

    return 0;
}