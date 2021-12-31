#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Lasketaan kaikkien lukujen etäisyys mediaaniin.
 * Toimii parittomilla ja parillisilla n-luvuilla.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> luvut;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        luvut.push_back(a);
    }

    sort(luvut.begin(), luvut.end());

    int mediaani = luvut[n/2];

    long long summa = 0;
    for (auto l : luvut) {
        summa += abs(l-mediaani);
    }

    cout << summa;

    return 0;
}