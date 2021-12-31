#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1193
 *
 * Etsitään nopein reitti leveyshaulla (bfs).
 */

const int maxN = 1e7+1;
vector<int> tree[maxN];
bool visited[maxN];
int p[maxN];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int alku;
    int loppu = 0;
    string aiempi;
    for (int i = 0; i < n; i++) {
        string rivi;
        cin >> rivi;
        for (int j = 0; j < m; j++) {
            if (rivi[j] == '.' || rivi[j] == 'A' || rivi[j] == 'B') {
                if (rivi[j] == 'A') alku = i*m+j;
                else if (rivi[j] == 'B') loppu = i*m+j;
                if (j > 0 && (rivi[j-1] == '.' || rivi[j-1] == 'A' || rivi[j-1] == 'B')) {
                    tree[i*m+j-1].push_back(i*m+j);
                    tree[i*m+j].push_back(i*m+j-1);
                }
                if (i > 0 && (aiempi[j] == '.' || aiempi[j] == 'A' || aiempi[j] == 'B')) {
                    tree[(i-1)*m+j].push_back(i*m+j);
                    tree[i*m+j].push_back((i-1)*m+j);
                }
            }
        }
        aiempi = rivi;
    }

    //bfs
    queue<int> q;
    q.push(alku);
    p[alku] = -1;
    visited[alku] = true;

    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto next : tree[s]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
            p[next] = s;
        }
    }
    if (!p[loppu]) {
        cout << "NO";
        return 0;
    }

    vector<int> reitti;
    for (int i = loppu; i != -1; i = p[i]) {
        reitti.push_back(i);
    }
    reverse(reitti.begin(), reitti.end());
    cout << "YES\n";
    cout << reitti.size()-1 << "\n";

    map<int,char> map;
    map[-1] = 'L';
    map[1] = 'R';
    map[m] = 'D';
    map[-m] = 'U';
    for (int i = 1; i < (int)reitti.size(); i++) {
        cout << map[reitti[i]-p[reitti[i]]];
    }
    cout << "\n";

    return 0;
}