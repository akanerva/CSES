#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Toteutetaan maksimiparitus järjestämällä hakijat ja hakukohteet multisetteihin.
 * Algoritmin nopeuttamiseksi poistetaan liian pienet asunnot pois kun niille ei
 * varmasti löydy enää hakijoita.
 *
 */
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, k;
    cin >> n >> m >> k;

    multiset<long long> apartments;
    multiset<long long> applicants;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        applicants.insert(a);
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        apartments.insert(b);
    }

    int c = 0;

    for (auto appli : applicants) {

        while (!apartments.empty() && *apartments.begin() < appli-k) {
            apartments.erase(apartments.begin());
        }
        for (auto apa : apartments) {
            if (appli <= apa+k && appli >= apa-k) {
                c++;
                apartments.erase(apartments.find(apa));
                break;
            }
            if (appli+k < apa) break;
        }
    }

    cout << c;


    return 0;
}