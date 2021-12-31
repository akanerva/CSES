#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Minimiviritetty segmenttipuu.
 */

const int maxN = 4e5+2;
int n;
int tree[maxN];

// etsi välin a...b pienin alkio
int getMin(int a, int b) {
    a += n; b += n;
    int x = tree[a];
    while (a <= b) {
        if (a%2 == 1) x = min(x, tree[a++]);
        if (b%2 == 0) x = min(x, tree[b--]);
        a /= 2; b /= 2;
    }
    return x;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = n + 1; i <= (n << 1); i++) {
        cin >> tree[i];
    }
    for (int i = n; i > 0; --i) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << getMin(a, b) << "\n";
    }

    return 0;
}