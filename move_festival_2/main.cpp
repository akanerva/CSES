#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Laitetaan jäsenet katsomaan aikaisimmin päättyvät elokuvat ensimmäisenä.
 * Elokuva osoitetaan jäsenelle jolla loppuu myöhäisimpään aiempi katsomansa elokuva.
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    multiset<pair<int, int>> leffat;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        leffat.insert({b, a});
    }

    /*
    //print järjestys
    auto printti = leffat.begin();
    cout << "\n";
    while (printti != leffat.end()) {
        cout << printti->first << " " << printti->second << "\n";
        ++printti;
    }
    */
    int res = 0;

    multiset<int, greater<int>> jasenet;
    for (int i = 0; i < k; i++) {
        jasenet.insert(0);
    }

    while (!leffat.empty()) {
        auto leffa = leffat.begin();
        auto jasen = jasenet.lower_bound(leffa->second);

        if (jasen != jasenet.end()) {
            res++;
            jasenet.insert(leffa->first);
            jasenet.erase(jasen);
        }
        leffat.erase(leffa);
    }

    cout << res;

    return 0;
}