#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Lasketaan luku indeksien perusteella sen sijaan että
 * oikeasti täytettäisiin taulukko.
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<pair<int, int>> kyselyt;
    for (int i = 0; i < t; i++) {
        int y, x;
        cin >> y >> x;
        kyselyt.emplace_back(y, x);
    }

    for (auto& k : kyselyt) {
        long long vastaus = 0;
        if (k.first >= k.second) {
            if (k.first % 2 == 0) {
                vastaus = k.first;
                vastaus *= vastaus;
                vastaus -= k.second-1;
            }
            else {
                vastaus = k.first-1;
                vastaus *= vastaus;
                vastaus += 1;
                vastaus += k.second-1;
            }

        }
        else {
            if (k.second % 2 == 1) {
                vastaus = k.second;
                vastaus *= vastaus;
                vastaus -= k.first-1;
            }
            else {
                vastaus = k.second-1;
                vastaus *= vastaus;
                vastaus += 1;
                vastaus += k.first-1;
            }
        }
        cout << vastaus << "\n";
    }

    return 0;
}