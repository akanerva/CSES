#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1196
 *
 * Sovelletaan dijkstraa, mutta jokaiselle nodelle on yhden arvon
 * sijasta k arvoa vectoriin järjestettynä parhaimmasta huonoimpaan.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;

    vector<pair<int,int>> tree[n+1];
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        tree[a].emplace_back(b,c);
    }

    priority_queue <
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
    > pq;  // {cost, node}

    vector<vector<long long>> dist;
    dist.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        dist[i].resize(k);
        for (int j = 0; j < k; ++j) {
            dist[i][j] = 1e15;
        }
    }
    //dist[1][0] = 0;

    pq.push({0,1});

    while (!pq.empty()) {
        long long cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if (cost > dist[curr][k-1]) continue;

        for (auto next : tree[curr]) {
            if (cost+next.second < dist[next.first][k-1]) {
                dist[next.first][k-1] = cost+next.second;
                pq.push({dist[next.first][k-1], next.first});
                sort(dist[next.first].begin(), dist[next.first].end());
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << dist[n][i] << " ";
    }

    return 0;
}