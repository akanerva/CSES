#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Jos pisin kirja on pitempi kuin loput kirjat yhteensä,
 * joudutaan odottaa pisimmän kirjan loppuun lukemista.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long summa = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        mx = max(mx, k);
        summa += k;
    }

    cout << (mx > summa-mx ? 2*mx : summa);

    return 0;
}