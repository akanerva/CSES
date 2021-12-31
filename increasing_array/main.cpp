#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1094
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long min = 0;
    long vastaus = 0;
    for (int i = 0; i < n; i++) {
        int luku;
        cin >> luku;
        if (luku < min) {
            vastaus += min-luku;
        }
        else {
            min = luku;
        }
    }
    cout << vastaus;

    return 0;
}