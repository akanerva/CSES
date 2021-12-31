#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Säilötään luvut ja indeksit pareina.
 * Sorttaamisen jälkeen verrataan kahden luvun summia alusta ja lopusta kunnes kohdataan.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> luvut;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        luvut.emplace_back(a, i);
    }

    sort(luvut.begin(), luvut.end());
    int j = n-1;
    for (int i = 0; i < j; i++) {
        while (luvut[i].first + luvut[j].first > x && j > i+1) j--;
        if (luvut[i].first + luvut[j].first == x) {
            cout << luvut[i].second << " " << luvut[j].second;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}