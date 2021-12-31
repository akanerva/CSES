#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5+2;

/**
 *
 * akanerva
 *
 * https://cses.fi/problemset/task/1671
 *
 * bfs/bellman-ford -muunnelma kaupungista 1.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v[maxN];
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].emplace_back(b,c);
    }

    // bfs/bellman-ford
    set<int> ss;
    vector<long long> d(n+1, LLONG_MAX);
    d[1] = 0;
    ss.insert(1);

    while (!ss.empty()) {
        int s = *ss.begin(); ss.erase(s);
        for (auto next : v[s]) {
            long long check = d[s]+next.second;
            if (check < d[next.first]) {
                ss.insert(next.first);
                d[next.first] = check;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " ";
    }

    return 0;
}