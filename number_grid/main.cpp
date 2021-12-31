#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * huppispuppis menikin vaikeeks
 *
 */
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> y >> x;
    if (y == x) {
        cout << 0;
        return 0;
    }

    cout << y-1 + x-1;
    return 0;
}