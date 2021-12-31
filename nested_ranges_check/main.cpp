#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/2168
 *
 * Naiivi ratkaisu: sorttaa ranget ja tarkasta brute forcella. Liian hidas.
 *
 * Sorttaamalla ranget pienemmän arvon mukaan löydetään O(n log n)-aikainen ratkaisu.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> ranget(n);
    map<pair<int,int>, int> kyselyt;
    vector<int> sisalto(n);
    vector<int> sisaltyy(n);
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        ranget[i] = {a,b};
        kyselyt[{a,b}] = i;
    }
    sort(ranget.begin(), ranget.end(), [](auto &left, auto &right) {
        if (left.first == right.first) return left.second > right.second;
        return left.first < right.first;
    });

    int maxEnd = 0;
    int minEnd = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (ranget[i].second <= maxEnd)
            sisaltyy[kyselyt[{ranget[i].first,ranget[i].second}]] = 1;

        maxEnd = max(maxEnd, ranget[i].second);
    }

    for (int i = n-1; i >= 0; --i) {
        if (ranget[i].second >= minEnd)
            sisalto[kyselyt[{ranget[i].first,ranget[i].second}]] = 1;

        minEnd = min(minEnd, ranget[i].second);
    }

    for (auto x : sisalto) {
        cout << x << " ";
    }
    cout << "\n";

    for (auto x : sisaltyy) {
        cout << x << " ";
    }

    return 0;
}