#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Lasketaan dynaamisesti kaikki mahdolliset summat.
 * Haetaan summa joka on lähimpänä taulukon lukujen summan puolikasta.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> luvut;
    long long summa = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        luvut.push_back(a);
        summa += a;
    }
    if (n == 1) {
        cout << summa;
        return 0;
    }

    long long min = summa;
    long long tavoite = summa/2;

    set<long long> summat;

    for (int l : luvut) {
        vector<long long> temp;
        for (long long s : summat) {
            temp.push_back(l+s);
        }
        summat.insert(l);
        for (long long t : temp) {
            summat.insert(t);
        }
    }
    long long pino;
    for (auto &s : summat) {

        long long ero = tavoite-s;
        ero = abs(ero);
        if (ero < min) {
            min = ero;
            pino = s;
        }
        if (min == 0) break;
    }
    pino = summa-pino-pino;
    pino = abs(pino);
    cout << pino;


    return 0;
}