#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1669/
 *
 * Tarkoituksena löytää ja kulkea sykli.
 */

const int maxN = 1e5+1;
vector<int> tree[maxN];
int n;
bool used[maxN];
int p[maxN];

int dfs(int node, int prev) {
    used[node] = true;
    for (auto next : tree[node]) {
        if (next == prev) continue;
        p[next] = node;
        // sykli havaittu
        if (used[next]) {
            return next;
        }
        int haara = dfs(next,node);
        if (haara) return haara;
    }
    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            int sykli = dfs(i,0);

            if (sykli) {
                vector<int> reitti;
                reitti.push_back(sykli);
                int j = p[sykli];

                while (j != sykli) {
                    reitti.push_back(j);
                    j = p[j];
                }
                reitti.push_back(j);
                cout << reitti.size() << "\n";
                for (auto &a : reitti) cout << a << " ";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}