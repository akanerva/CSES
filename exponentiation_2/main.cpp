#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Fermat'n pieni lause
 */

int pot(long long x, long long n, int m) {
    if (n == 0) return 1 % m;

    long long u = pot(x,n/2,m);
    u = ((u % m) * (u % m)) % m;

    if (n % 2 == 1) u = ((u % m) * (x % m)) % m;

    return u;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    int m = 1e9+7;

    while (n--) {
        int a,b,c;
        cin>>a>>b>>c;
        cout << pot(a,(pot(b,c,m-1)),m) << "\n";
    }

    return 0;
}