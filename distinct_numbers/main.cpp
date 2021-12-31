#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Säilötään luvut setissä ja printataan setin koko.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; i++) {
        int luku;
        cin >> luku;
        S.insert(luku);
    }

    cout << S.size();

    return 0;
}