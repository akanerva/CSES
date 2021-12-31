#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<pair<int, int>> MS;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        MS.insert({b, a});
    }

    auto it = MS.begin();
    int c = 1;
    int loppu = it->first;
    while (it != MS.end()) {
        if (it->first > loppu && it->second >= loppu) {
            c++;
            loppu = it->first;
        }
        it++;
    }

    cout << c;
    return 0;
}