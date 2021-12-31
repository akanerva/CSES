#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Katujen alku- ja loppupäät parina settiin, pituudet mappiin.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    vector<int> valot;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        valot.push_back(p);
    }

    set<pair<int, int>, greater<pair<int, int>>> kadut;
    map<int, int> pituudet;

    kadut.insert({0, x});
    pituudet[x]++;

    for (int p : valot) {
        auto it = kadut.lower_bound({p, 1e9+5});
        kadut.insert({p, it->second});
        kadut.insert({it->first, p});
        pituudet[it->second - p]++;
        pituudet[p - it->first]++;

        pituudet[it->second - it->first]--;
        if (pituudet[it->second - it->first] == 0) pituudet.erase(it->second - it->first);
        kadut.erase(it);

        cout << pituudet.rbegin()->first << " ";
    }
    return 0;
}