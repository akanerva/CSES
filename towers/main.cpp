#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Ilmeisesti vectorillakin pelittäisi upper_bound?
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    multiset<int> tornit;
    int c = 0;
    for (int i : input) {
        auto it = tornit.upper_bound(i);
        if (it != tornit.end()) tornit.erase(it);

        if (i == 1)
            c++;
        else
            tornit.insert(i);
    }
    cout << tornit.size()+c;

    return 0;
}