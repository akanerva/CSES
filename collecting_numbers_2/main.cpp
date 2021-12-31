#include <bits/stdc++.h>

using namespace std;

/**
 *
 * akanerva
 *
 * https://cses.fi/problemset/task/2217
 *
 * Tarkastetaan vaihtojen vaikutus taulukon lukujen inversioihin
 * (eli permutaatiossa luku ennen sen edeltäjää) ja mukautetaan
 * res-muuttuja sen mukaisesti. O(n)-aikainen algoritmi.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> luvut(n+1);
    vector<int> ind(n+1); // <luku,indeksi>
    ind[0] = 0;
    ind[n+1] = n+1;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        luvut[i] = a;
        ind[a] = i;
        if (ind[a-1] > i || ind[a-1] == 0) res++;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        set<pair<int,int>> s;
        s.insert({luvut[a]-1,luvut[a]});
        s.insert({luvut[a],luvut[a]+1});
        s.insert({luvut[b]-1,luvut[b]});
        s.insert({luvut[b],luvut[b]+1});

        //ei lasketa duplikaattipareja
        for (auto x : s) {
            if (ind[x.first] > ind[x.second]) res--;
        }

        swap(luvut[a],luvut[b]);
        ind[luvut[a]] = a;
        ind[luvut[b]] = b;

        for (auto x : s) {
            if (ind[x.first] > ind[x.second]) res++;
        }

        cout << res << "\n";
    }

    return 0;
}