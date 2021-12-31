#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1197
 *
 * Bellman-Ford muokkaa x:n arvoa n:nnellä kierroksella negatiivisen syklin löydettyään.
 */

const int maxN = 2501;

vector<pair<int,int>> tree[maxN];


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin>>a>>b>>c;
        tree[a].emplace_back(b,c);
    }

    vector<long long> e(n+1);
    vector<int> relax(n+1);
    for (int i = 1; i <= n; i++) relax[i] = -1;

    int x = 0;
    for (int i = 1; i <= n; i++) {
        x = -1;
        for (int a = 1; a <= n; a++) {
            for (auto b : tree[a]) {
                long long check = e[a]+b.second;
                if (check < e[b.first]) {
                    e[b.first] = check;
                    relax[b.first] = a;
                    x = b.first;
                }
            }
        }
    }

    if (x == -1) {
        cout << "NO";
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        x = relax[x];
    }

    vector<int> sykli;
    for (int u = x; ; u = relax[u]) {
        sykli.push_back(u);
        if (u == x && sykli.size() > 1) break;
    }
    reverse(sykli.begin(),sykli.end());

    cout << "YES\n";
    for (auto a : sykli) {
        cout << a << " ";
    }

    return 0;
}