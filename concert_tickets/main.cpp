#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<int, int> liput;
    vector<int> maksimit;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        liput[-h]++;
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        maksimit.push_back(-t);
    }

    for (auto &ma : maksimit) {
        auto it = liput.lower_bound(ma);
        //auto it = lower_bound(liput.begin(), liput.end(), ma);
        if (it != liput.end()) {
            cout << -(it->first) << "\n";
            it->second--;
            if (it->second < 1) liput.erase(it);
        }
        else {
            cout << -1 << "\n";
        }
    }

    return 0;
}