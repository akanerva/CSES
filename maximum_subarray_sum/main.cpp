#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * O(n)-aikainen haku maksimin löytämiseksi.
 *
 */
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> luvut;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        luvut.push_back(a);
    }

    long long p = luvut[0];
    long long s = luvut[0];

    //kkkk
    for (int i = 1; i < n; i++) {
        long long temp = luvut[i];
        long long temp2 = s+luvut[i];
        s = max(temp, temp2);
        p = max(p, s);
    }

    cout << p;

    return 0;
}