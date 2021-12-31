#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Editointietäisyys/Levenshteinin etäisyys kkkk:sta.
 */

const int N = 5002;

int dp[N][N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 1; i <= str1.length(); i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= str2.length(); i++) {
        dp[i][0] = i;
    }

    for (int i = 1; i <= str2.length(); i++) {
        for (int j = 1; j <= str1.length(); j++) {
            if (str1[j-1] == str2[i-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
            }
        }
    }

    /*
    //dp-taulukon print
    for (int i = 0; i <= str2.length(); i++) {
        for (int j = 0; j <= str1.length(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */

    cout << dp[str2.length()][str1.length()];

    return 0;
}