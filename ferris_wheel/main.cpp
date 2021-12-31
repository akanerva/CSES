#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Tallennetaan lapsien painot negatiivisina multisettiin.
 * Ladataan istuinpareihin begin() ja lower_bound(-x - *begin()).
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    multiset<int> lapset;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        lapset.insert(-p);
    }
    int c = 0;
    while (!lapset.empty()) {
        auto it = lapset.begin();
        int ero = -x - *it;
        lapset.erase(it);
        if (ero < 0) {
            auto it2 = lapset.lower_bound(ero);
            if (it2 != lapset.end()) lapset.erase(it2);
        }
        c++;
    }

    cout << c;


    return 0;
}