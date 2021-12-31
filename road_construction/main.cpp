#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1676
 *
 * Union-find-rakennetta päivitetään ja pidetään yllä msf suurimmasta joukosta,
 * sekä miinustetaan joukkojen kokoa aina kun liitetään eri komponentit yhteen?
 *
 */

const int maxN = 1e5+1;

int k[maxN]; //seuraava ketjussa, tai alkio itsessään jos joukon edustaja
int s[maxN]; //joukon koko

//palauttaa joukon edustajan
int id(int x) {
    while (x != k[x]) x = k[x];
    return x;
}

//kuuluvatko alkiot samaan joukkoon
bool sama(int a, int b) {
    return id(a) == id(b);
}

//liittää pienemmän joukon suurempaan
void liita(int a, int b) {
    a = id(a);
    b = id(b);
    if (s[b] > s[a]) swap(a,b);
    s[a] += s[b];
    k[b] = a;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        k[i] = i;
        s[i] = 1;
    }

    int msf = 0; //maksimijoukon koko
    int joukot = n; //joukkojen määrä

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        if (!sama(a,b)) {
            liita(a,b);
            msf = max(msf, s[id(a)]);
            joukot--;
        }

        cout << joukot << " " << msf << "\n";
    }

    return 0;
}