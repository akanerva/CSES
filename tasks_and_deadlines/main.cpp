#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Suoritetaan tehtävät ahneesti keston mukaan alkaen nopeimmasta.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> dl;
    for (int i = 0; i < n; ++i) {
        int d, f;
        cin >> d >> f;
        dl.emplace_back(d, f);
    }

    sort(dl.begin(), dl.end());
    long long reward = 0;
    long long aika = 0;
    for (auto a : dl) {
        aika += a.first;
        reward += a.second - aika;
    }
    cout << reward;

    return 0;
}