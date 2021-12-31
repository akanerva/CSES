#include <bits/stdc++.h>

using namespace std;


bool ok(const long long &k, const long long &t, const vector<int> &koneet) {

    long long summa = 0;

    for (auto kone : koneet) {
        summa += k/kone;
    }
    return summa >= t;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, t;
    cin >> n >> t;

    vector<int> koneet;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        koneet.push_back(a);
    }
    sort(koneet.begin(), koneet.end());

    long long k = -1;
    for (long long b = koneet[0]*t; b >= 1; b /= 2) {
        while (!ok(k+b, t, koneet)) k+= b;
    }

    cout << k+1;

    return 0;
}