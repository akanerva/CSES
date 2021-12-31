#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 */
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> M;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        M[a]++;
        M[b]--;
    }
    int max = 0;
    int curr = 0;

    for (auto it = M.begin(); it != M.end(); it++) {
        curr += it->second;
        if (curr > max) max = curr;
    }

    cout << max;

    return 0;
}