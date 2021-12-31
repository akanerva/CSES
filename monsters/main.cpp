#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Ajetaan bfs kaikille agenteille samanaikaisesti.
 */

const int maxN = 1e6+1; //1d matriisi
vector<int> tree[maxN];
int used[maxN]; //0 - koskematon, 1 - mörkö kulkenut, 2 - A kulkenut
int p[maxN];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<char,int> map1;
    map1['M'] = 1;
    map1['A'] = 1;
    map1['.'] = 1;
    map1['#'] = 0;
    vector<int> monsterit;
    int alku;
    string aiempi;
    for (int i = 0; i < n; i++) {
        string rivi;
        cin >> rivi;
        for (int j = 0; j < m; j++) {
            if (map1[rivi[j]]) { //jos ei seinä
                if (rivi[j] == 'A') alku = i*m+j;
                else if (rivi[j] == 'M') monsterit.push_back(i*m+j);
                if (i > 0 && map1[aiempi[j]]) {
                    tree[i*m+j].push_back((i-1)*m+j);
                    tree[(i-1)*m+j].push_back(i*m+j);
                }
                if (j > 0 && map1[rivi[j-1]]) {
                    tree[i*m+j].push_back(i*m+j-1);
                    tree[i*m+j-1].push_back(i*m+j);
                }
            }
        }
        aiempi = rivi;
    }

    //bfs
    queue<int> q, qm;
    q.push(alku); //A:n jono
    p[alku] = -1;
    used[alku] = 2;
    for (auto a : monsterit) {
        qm.push(a); //mörköjen jono
        used[a] = 1;
    }

    //bfs möröille ensin, sitten A-agentille
    while (!q.empty()) {
        //möröt liikkuu yhden tason
        int tm = qm.size();
        while (tm--) {
            int s = qm.front();
            qm.pop();
            for (auto next : tree[s]) {
                if (used[next] == 1) continue;
                used[next] = 1;
                qm.push(next);
            }
        }
        //A liikkuu yhden tason
        tm = q.size();
        while (tm--) {
            int s = q.front();
            //jos maali
            if (s < m || s >= (n-1)*m || s % m == 0 || s % m == m-1) {
                cout << "YES\n";
                vector<int> reitti;
                for (int i = s; i != -1; i = p[i]) {
                    reitti.push_back(i);
                }
                reverse(reitti.begin(), reitti.end());
                cout << reitti.size()-1 << "\n";

                map<int,char> map2;
                map2[-1] = 'L';
                map2[1] = 'R';
                map2[m] = 'D';
                map2[-m] = 'U';
                for (int i = 1; i < (int)reitti.size(); i++) {
                    cout << map2[reitti[i]-p[reitti[i]]];
                }
                cout << "\n";
                return 0;
            }
            q.pop();
            for (auto next : tree[s]) {
                if (used[next]) continue;
                used[next] = 2;
                q.push(next);
                p[next] = s;
            }
        }
    }

    cout << "NO";

    return 0;
}