#include <bits/stdc++.h>

using namespace std;


/**
 * akanerva
 * Pque<greater> huoneille.
 * Erilliset säiliöt asiakkaiden tulo- ja lähtöpäiville.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> tulevat;
    set<pair<int, int>> lahtevat; //set jos ei onnaa pq
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        tulevat.emplace_back(x, i);
        lahtevat.insert({y, i});
    }

    sort(tulevat.begin(), tulevat.end());
    vector<int> ans(n);
    int huone_max = 0;
    //int sijoitus[20001];
    map<int, int> sij;
    priority_queue<int, vector<int>, greater<>> huoneet;

    for (auto &t : tulevat) {
        while (lahtevat.begin()->first < t.first)  {
            huoneet.push(sij[lahtevat.begin()->second]);
            lahtevat.erase(lahtevat.begin());
        }
        if (huoneet.empty()) huoneet.push(++huone_max);

        ans[t.second] = huoneet.top();
        sij[t.second] = huoneet.top();
        huoneet.pop();
    }

    cout << huone_max << "\n";
    for (auto &a : ans) {
        cout << a << " ";
    }

    return 0;
}