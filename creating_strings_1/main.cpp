#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Sortataan string aakkosjärkkään.
 * Hyödynnetään stl:n next_permutation -algoritmia.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    sort(n.begin(), n.end());

    vector<string> mjonot;
    mjonot.push_back(n);
    while (next_permutation(n.begin(), n.end())) {
        mjonot.push_back(n);
    }

    cout << mjonot.size() << "\n";

    for (auto &mjono : mjonot) {
        cout << mjono << "\n";
    }

    return 0;
}