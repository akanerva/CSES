#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3+1;
int hs[maxN][maxN]; //horisontaalinen summa vasemmalta
int s[maxN][maxN]; //2d summa

/**
 *
 * akanerva
 *
 * https://cses.fi/problemset/task/1652
 *
 * O(n)-aikainen summapuun luominen ja O(1)-aikaiset kyselyt.
 *
 */


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    //input
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        for (int j = 1; j <= n; ++j) {
            hs[i][j] = hs[i][j-1];
            s[i][j] = hs[i][j-1]+s[i-1][j];
            if (str[j-1] == '*') {
                hs[i][j]++;
                s[i][j]++;
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int y1,x1,y2,x2;
        cin >> y1>>x1>>y2>>x2;
        cout << s[y2][x2]-s[y2][x1-1]-s[y1-1][x2]+s[y1-1][x1-1] << "\n";
    }

    //summataulukko

    return 0;
}
