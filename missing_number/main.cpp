#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1083/
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool ar[500001];
    for (int i = 0; i < n-1; i++) {
        int luku;
        cin >> luku;
        ar[luku] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!ar[i]) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}