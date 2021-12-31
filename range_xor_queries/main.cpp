#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Xor-segmenttitaulukko.
 */

const int maxN = 4e5+4;

int n;
long long tree[maxN];

/*
void change(int k, int x) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k]^tree[2*k+1];
    }
}
*/
long long getXor(int a, int b) {
    a += n; b += n;
    long long s = 0;
    while (a <= b) {
        if (a%2 == 1) s ^= tree[a++];
        if (b%2 == 0) s ^= tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = n+1; i <= 2*n; i++) {
        cin >> tree[i];
    }
    for (int i = n; i > 0; --i) {
        tree[i] = tree[2*i]^tree[2*i+1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << getXor(a,b) << "\n";
    }

    return 0;
}