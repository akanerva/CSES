#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/**
 * akanerva
 * tuplasti kahden osoittimen tekniikka.
 *
 */
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<pair<ll, int>> luvut;
    for (int i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        luvut.emplace_back(a, i);
    }
    sort(luvut.begin(), luvut.end());

    for (int i = 0; i < n-2; ++i) {
        for (int j = n-1; j > i+2; --j) {
            for (int k = i+1, l = j-1; k < l; ++k) {
                while (luvut[i].first+luvut[j].first+luvut[k].first+luvut[l].first > x && l > k+1) --l;

                if (luvut[i].first+luvut[j].first+luvut[k].first+luvut[l].first == x) {
                    cout << luvut[i].second << " " << luvut[j].second << " " <<
                    luvut[k].second << " " << luvut[l].second;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}