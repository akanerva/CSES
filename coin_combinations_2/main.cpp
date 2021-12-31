#include <bits/stdc++.h>

using namespace std;
const int M = 1e9+7;
const int N = 1e6+5;
long long d[N];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    vector<int> c;
    c.push_back(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int kolikko;
        cin >> kolikko;
        c.push_back(kolikko);
    }

    d[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= x; i++) {
            if (i-c[j] >= 0) {
                d[i] = (d[i] + d[i-c[j]]) % M;
            }
            /*
            d[i] += d[i-c[j]];
            d[i] %= M;
             */
        }
    }

    /*
    for (int i = 1; i <= n; i++) {
        cout << d[i] << "\n";
    }*/

    cout << d[x];

    return 0;
}