#include <bits/stdc++.h>

using namespace std;

/**
 *  akanerva
 *
 *  https://cses.fi/problemset/task/1678
 *
 *  kosarajulla etsitään joukko jossa vähintään 2 solmua,
 *  ja vain lähtösolmussa käydään kahesti.
 *
 *  tässä tehtävässä ei tarvitse tallentaa vahvasti yhteneväisiä joukkoja
 *  muistiin; syklin löydettyä se tulostetaan.
 */

const int maxN = 1e5+1;
vector<int> tree[maxN];
vector<int> tree2[maxN]; //reversed
vector<int> v;


bool used[maxN];
bool used2[maxN];

void kosaraju(int curr) {
    used[curr] = true;
    for (auto next : tree[curr]) {
        if (!used[next]) kosaraju(next);
    }
    v.push_back(curr);
}

bool kosaraju2(int curr, int goal, int depth) {
    if (curr == goal && depth > 1) {
        cout << depth << "\n";
        cout << curr << " ";
        return true;
    }
    used2[curr] = true;

    for (auto next : tree2[curr]) {
        if (used2[next] && next != goal) continue;
        if (kosaraju2(next,goal,depth+1)) {
            cout << curr << " ";
            return true;
        }
    }
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
        tree2[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) kosaraju(i);
    }
    reverse(v.begin(), v.end());

    for (auto a : v) {
        //cout << a << " ";
        if (!used2[a]) {
            if (kosaraju2(a,a,1)) return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}