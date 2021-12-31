#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1673
 *
 * Bellman-Ford algoritmi muokattu etsimään suurin reitti.
 * n:nnellä kierroksella huomataan positiivinen sykli jos jonkun solmun arvo on noussut.
 * Jos on, niin tarkastetaan että 1-noussutsolmu-n -reitti on mahdollinen => print -1
 */

const int maxN = 2501;

vector<pair<int,int>> tree[maxN];

set<int> cycles; //solmut jotka kuuluvat sykliin/sykleihin
bool used[maxN];
bool used2[maxN];

void dfs(int curr, int goal) {
    used[curr] = true;
    for (auto next : tree[curr]) {
        if (!used[next.first]) {
            dfs(next.first, goal);
        }
    }
}

bool dfs2(int curr, int goal) {
    if (curr == goal) return true;
    if (used2[curr]) return false;
    used2[curr] = true;
    for (auto next : tree[curr]) {
        if (!used2[next.first]) {
            if (dfs2(next.first, goal)) return true;
        }
    }
    return false;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].emplace_back(b, c);
    }

    vector<long long> dist(n + 1);
    for (int i = 2; i <= n; i++) dist[i] = -1e10;

    for (int i = 1; i <= n-1; i++) {
        for (int a = 1; a <= n; a++) {
            for (auto b : tree[a]) {
                long long check = dist[a] + b.second;
                if (check > dist[b.first]) dist[b.first] = check;
            }
        }
    }

    bool x = false;
    for (int a = 1; a <= n; a++) {
        for (auto b : tree[a]) {
            long long check = dist[a] + b.second;
            if (check > dist[b.first]) {
                dist[b.first] = check;
                x = true;
                cycles.insert(b.first);
            }
        }
    }

    if (x) {
        dfs(1,n);
        for (auto a : cycles) {
            if (used[a]) {
                if (dfs2(a,n)) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << dist[n];
    return 0;
}