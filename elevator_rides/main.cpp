#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1653
 *
 * https://cses.fi/book/book.pdf s103-104
 *
 * Itse toteutus ei tullut täysin ymmärrettyä, varsinkaan alijoukkojen
 * muodostaminen xorreilla ja andeilla sekä niiden pyörittäminen, mutta
 * idean toki ymmärsin yllä linkatusta selostuksesta.
 */

const int maxN = 20;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    int weight[maxN];
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    pair<int,int> best[1<<maxN];
    best[0] = {1,0};


    for (int s = 1; s < (1<<n); s++) {
        // initial value: n+1 rides are needed
        best[s] = {n+1,0};
        for (int p = 0; p < n; p++) {
            if (s&(1<<p)) {
                auto option = best[s^(1<<p)];
                if (option.second+weight[p] <= x) {
                    // add p to an existing ride
                    option.second += weight[p];
                } else {
                    // reserve a new ride for p
                    option.first++;
                    option.second = weight[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }
    /*
    for (int i = 1; i < (1<<n); ++i) {
        cout << i << " - " << best[i].first << "," << best[i].second << "\n";
    }*/
    cout << best[(1<<n)-1].first;

    return 0;
}