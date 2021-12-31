#include <bits/stdc++.h>

using namespace std;

const int M = 1e9+7;
long long rivi[1001]; // jostain syystä tämän täytyy olla globaali

/**
 * akanerva
 *
 * Lasketaan polkujen määrä dynaamisesti. Uusi polku muodostuun kun
 * pisteeseen pääsee kulkemaan sekä ylhäältä että alhaalta.
 * Polku nollataan ansan (*) kohdalla. Lasketaan dynaamisesti
 * päivittäen yhtä riviä.
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    rivi[0] = 1;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < n; j++) {
            if (str[j] == '*') rivi[j] = 0;
            else {
                if (j > 0) {
                    rivi[j] += rivi[j-1];
                    rivi[j] %= M;
                }
            }
        }

        //print
        /*
        for (int j = 0; j < n; j++) {
            cout << rivi[j] << ", ";
        }
        cout << "\n";
         */
    }



    cout << rivi[n-1];

    return 0;
}