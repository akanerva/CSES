#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/**
 * akanerva
 * Pigeonhole principle.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> luvut;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        luvut.push_back(a);
    }

    ll summa = 0, c = 0;
    map<int, int> m;
    m[0]++;

    for (int i = 0; i < n; ++i) {
        (summa += luvut[i]) %= n;
        if (summa < 0) summa += n;
        auto it = m.find((summa+n) % n);
        if (it != m.end()) c += it->second;
        m[summa]++;
    }

    cout << c;

    return 0;
}