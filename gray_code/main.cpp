#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 *
 */

int n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        int val = (i ^ (i >> 1));

        bitset<32> r(val);

        string s = r.to_string();
        cout << s.substr(32-n) << "\n";
    }


    return 0;
}