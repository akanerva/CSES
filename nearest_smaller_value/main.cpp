#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Poistetaan säiliöstä luvut jotka eivät voi olla enää vastauksia.
 *
 */
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<pair<int, int>> luvut;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        luvut.insert({i, x});
    }

    auto it = luvut.begin();
    for (; it != luvut.end(); ++it) {
        while (true) {
            auto it2 = it;
            if (it2 != luvut.begin() && (--it2)->second > it->second) luvut.erase(it2);
            else
                break;
        }
        auto it2 = it;
        while (true) {
            if (it2 == luvut.begin()) {
                cout << "0 ";
                break;
            }
            if ((--it2)->second < it->second) {
                cout << it2->first << " ";
                break;
            }
        }
    }

    return 0;
}