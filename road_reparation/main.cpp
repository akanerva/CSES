#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1675
 *
 * Kruskalin algoritmilla toteutetaan minimiviritetty puu.
 *
 * Union-find-rakenne
 *
 * kkkk s.137
 */

//puu structiin ja sorttaa costin mukaan?
struct edge {
    int a;
    int b;
    int cost;
    edge (int as, int bs, int c) { //constructor
        a = as;
        b = bs;
        cost = c;
    }
};

const int maxN = 1e5+1;
vector<edge> tree; //{cost,destination}
int k[maxN]; //seuraava alkio ketjussa ? kertoo alkion edustajan?
int s[maxN]; //montako alkiota edustajan joukossa on
long long w[maxN]; // edustajan joukon totaalipaino


//kertoo alkion x joukon edustajan
int id(int x) {
    while (x != k[x]) x = k[x];
    return x;
}

//ovatko a ja b samassa joukossa
bool sama(int a, int b) {
    return id(a) == id(b);
}

//liittää a:n ja b:n joukot yhdeksi joukoksi. liittää pienemmän suurempaan.
void liita(int a, int b, long long weight) {
    a = id(a);
    b = id(b);
    if (s[b] > s[a]) swap(a,b);
    s[a] += s[b];
    k[b] = a;

    w[a] += w[b] + weight;
}

bool sorter(edge a, edge b) {
    return (a.cost < b.cost);
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >>a>>b>>c;
        struct edge e = edge(a,b,c);
        tree.emplace_back(e);
    }

    sort(tree.begin(), tree.end(), sorter);

    for (int i = 1; i <= n; ++i) {
        k[i] = i;
        s[i] = 1;
    }

    int msf = 0;
    for (int i = 0; i < m; ++i) {
        if (!sama(tree[i].a, tree[i].b)) {
            liita(tree[i].a, tree[i].b, tree[i].cost);
            msf = max(msf, s[id(tree[i].a)]);
        }
        if (msf == n) {
            cout << w[id(1)];
            return 0;
        }
    }

    cout << "IMPOSSIBLE";




    return 0;
}