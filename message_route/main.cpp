#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1667
 *
 * bfs eli leveyshaku.
 *
 * Tätä toteutusta voisi vähän siistiä.
 * Haku pitäisi lopettaa kun n-solmu löytyy.
 * Lisäksi etäisyys-taulukko taitaa olla turha.
 */

const int maxN = 1e5+1;

vector<int> tree[maxN];
bool visited[maxN];
int etaisyys[maxN];
int vanhempi[maxN];


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

    queue<int> q;
    visited[1] = true;
    etaisyys[1] = 1;
    q.push(1);
    vanhempi[1] = -1;

    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto next : tree[s]) {
            if (visited[next]) continue;
            visited[next] = true;
            etaisyys[next] = etaisyys[s]+1;
            q.push(next);
            vanhempi[next] = s;
        }
    }
    if (etaisyys[n] == 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> reitti;
    for (int i = n; i != -1; i = vanhempi[i]) {
        reitti.push_back(i);
    }
    reverse(reitti.begin(), reitti.end());
    cout << etaisyys[n] << "\n";

    for (auto &a : reitti) {
        cout << a << " ";
    }


    return 0;
}