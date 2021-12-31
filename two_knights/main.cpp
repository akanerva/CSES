#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Combinatorics-juttuja.
 *
 */
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        long long vastaus = 0;
        long long koko = i*i;
        if (i == 2) vastaus = 6; // 4*3/2
        if (i > 2) vastaus += 4*(koko-3)/2; //nurkat
        if (i == 3) vastaus += 16; // keskiruutu ja sivut
        if (i > 3) {
            vastaus += 4*(koko-5)/2; // esim [1][1]
            vastaus += 8*(koko-4)/2; // esim [0][1], reunojen viereiset
        }
        if (i > 4) {
            vastaus += 4*(i-4)*(koko-5)/2; //sivu
            vastaus += 4*(i-4)*(koko-7)/2; //esim [1][2], n=5
            vastaus += (i-4)*(i-4)*(koko-9)/2; //keskus
        }

        cout << vastaus << "\n";
    }
    return 0;
}