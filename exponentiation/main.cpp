#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * tehokas potenssilasku kkkk:sta.
 */

const int M = 1e9+7;

int pot(int x, int n) {
    if (n == 0) return 1 % M;

    long long u = pot(x,n/2);
    u = ((u % M) * (u % M)) % M;

    if (n % 2 == 1) u = ((u % M) * (x % M)) % M;

    return u % M;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    while (n--) {
        int a,b;
        cin>>a>>b;
        cout << pot(a,b) << "\n";
    }

    return 0;
}