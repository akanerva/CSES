#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int res = 0;
    while (n > 0) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        n -= int(s[s.size()-1])-48;
        res++;
    }

    cout << res;


    return 0;
}