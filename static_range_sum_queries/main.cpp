#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Summataulukko.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 2; i <= n; i++) {
        v[i] += v[i-1];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << v[b]-v[a-1] << "\n";
    }

    return 0;
}