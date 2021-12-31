#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1140
 *
 * dp maksimipalkinnosta tiettyyn sortattuun projektin loppupäivään asti
 */

struct Proj {
    int alku, loppu;
    int arvo;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Proj> p;
    vector<long long> dp(n+1);
    Proj uglytemp = {0,0,0};
    p.push_back(uglytemp); // dp[0] == 0 ja p[0] == {0,0,0}
    for (int i = 0; i < n; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        Proj pro = {a,b,c};
        p.push_back(pro);
    }

    //sorttaa päättymispäivän mukaan
    sort(p.begin(), p.end(), [](auto &left, auto &right) {
        if (left.loppu == right.loppu) return left.alku < right.alku; //turha?
        return left.loppu < right.loppu;
    });

    for (int i = 1; i <= n; ++i) {
        //binäärihaku
        int k = 0;
        for (int b = n; b >= 1; b /= 2) {
            while (k+b < n && p[k+b].loppu < p[i].alku) k += b;
        }
        dp[i] = max(dp[i-1], dp[k]+p[i].arvo);
    }
    /*
    for (auto x : p) {
        cout << x.alku << ", " << x.loppu << ", " << x.arvo << "\n";
    }

    cout << "dp\n";
    for (int i = 0; i <= n; ++i) {
        cout << dp[i] << "\n";
    }
    */
    cout << dp[n];

    return 0;
}