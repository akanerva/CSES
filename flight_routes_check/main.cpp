#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1682
 *
 * Union-find -rakenne. Jos kaikki solmut eivät kuulu samaan joukkoon, niin "NO"
 * ja printataan joukkojen eri edustajat
 *
 * ^ väärä lähestymistapa, koska tiet ovat suunnattuja...
 *
 * vahvasti yhtenäiset joukot, ja tarkastetaan pääseekö kaikista joukoista toisiinsa?
 *
 *
 */

const int maxN = 1e5+1;

vector<pair<int,int>> tree;

int k[maxN];
int s[maxN];

int id(int x) {
    while (x != k[x]) {
        x = k[x];
    }
    return x;
}

bool sama(int a, int b) {
    return id(a) == id(b);
}

void liita(int a, int b) {
    a = id(a);
    b = id(b);
    if (s[b] > s[a]) swap(a,b);
    s[a] += s[b];
    k[b] = a;
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        tree.emplace_back(a,b);

    }
    for (int i = 1; i <= n; ++i) {
        k[i] = i;
        s[i] = 1;
    }

    int msf = 0;
    for (auto edge : tree) {
        if (!sama(edge.first,edge.second)) {
            liita(edge.first,edge.second);
            msf = max(msf, id(edge.first));
        }
    }
    if (msf == n) {
        cout << "YES";
        return 0;
    }

    cout << "NO\n";

    int a = id(1);
    for (int i = 2; i <= n; ++i) {
        if (id(i) != a) {
            cout << a << " " << id(i);
            break;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << i << " - " << id(i) << "\n";
    }

    return 0;
}