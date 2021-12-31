#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/**
 * akanerva
 * Kahden pointterin tekniikkaa.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> luvut;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        luvut.push_back(a);
    }
    ll sum = luvut[0];
    int c = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (sum < x && j < n-1) sum += luvut[++j];
        if (sum == x) ++c;
        sum -= luvut[i];
    }

    cout << c;

    return 0;
}