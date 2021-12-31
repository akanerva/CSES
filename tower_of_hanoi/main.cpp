#include <bits/stdc++.h>

using namespace std;


/**
 *
 * akanerva
 *
 * https://cses.fi/problemset/task/2165
 *
 * Ratkaistaan rekursiivisesti. Fuksivuodelta tuttu.
 *
 */

void hanoi(int n, int a, int b, int c) {
    if (n == 0) {
        return;
    }
    hanoi(n-1, a, c, b);
    cout << a << " " << c << "\n";
    hanoi(n-1, b, a, c);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << (1<<n)-1 << "\n"; // (2^n)-1
    hanoi(n, 1, 2, 3);
    return 0;
}