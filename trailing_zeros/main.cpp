#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Jokainen 5! lisää yhden nollan. Lisäksi jokainen 5*5! (jne kun <=n) lisää omansa.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int tulos = 0;
    for (int i = 5; i <= n; i *= 5) {
        tulos += n/i;
    }

    cout << tulos;
    return 0;
}