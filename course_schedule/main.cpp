#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Topologinen järjestys.
 * Sykli havaittu jos next on harmaa, muttei musta.
 *
 */

const int maxN = 1e5+1;

vector<int> tree[maxN];
bool grey[maxN];
bool black[maxN];
vector<int> res;

bool dfs(int curr) {
    grey[curr] = true;
    for (auto next : tree[curr]) {
        if (grey[next] && !black[next]) return true;
        if (!grey[next] && dfs(next)) return true;
    }
    black[curr] = true;
    res.push_back(curr);
    return false;
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

    for (int i = 1; i <= n; ++i) {
        if (!grey[i]) {
            if (dfs(i)) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for (int i = size(res)-1; i >= 0; --i) {
        cout << res[i] << " ";
    }


    return 0;
}