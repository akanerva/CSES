#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Tarvitsee käydä lista vain kertaalleen läpi. O(n)
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(v[i]-1) == s.end()) { //ei löydy
            res++;
        }
        s.insert(v[i]);
    }
    cout << res;

    return 0;
}