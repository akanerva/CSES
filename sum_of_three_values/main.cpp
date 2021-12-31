#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, long long>> luvut;
    for (int i = 1; i <= n; ++i) {
        long long a;
        cin >> a;
        luvut.emplace_back(a, i);
    }
    if (luvut.size() < 3) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    sort(luvut.begin(), luvut.end());

    for (unsigned int i = 0; i < luvut.size()-2; ++i) {
        for (unsigned int k = i+1, j = luvut.size()-1; k < j; ++k) {
            while (luvut[i].first + luvut[j].first + luvut[k].first > x && j > k+1) {
                --j;
            }
            if (luvut[i].first + luvut[j].first + luvut[k].first == x) {
                cout << luvut[i].second << " " << luvut[j].second << " " << luvut[k].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}