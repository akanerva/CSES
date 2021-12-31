#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1069
 *
 * O(n)-aikainen suoritus - käydään syöte läpi kerran.
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;
    int count = 1;
    int max_c = 1;
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == input[i-1]) {
            count++;
            max_c = max(max_c, count);
        }
        else {
            count = 1;
        }
    }
    cout << max_c << "\n";

    return 0;
}