#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int k;
vector<int> luvut;

/**
 * akanerva
 * Binäärihaku.
 *
 */

bool ok(ll maxsum) {

    int curnums = 1;
    ll cursum = 0;
    for (auto a : luvut) {
        if (a > maxsum) return false;
        if (cursum + a <= maxsum) {
            cursum += a;
        }
        else {
            cursum = a;
            curnums++;
            if (curnums > k) return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> k;

    ll kaik = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        kaik += a;
        luvut.push_back(a);
    }

    //binäärihaku 1 - suurin luku
    ll x = -1;
    for (ll b = kaik; b >= 1; b /= 2) {
        while (!ok(x+b)) x += b;
    }

    cout << x+1;

    return 0;
}