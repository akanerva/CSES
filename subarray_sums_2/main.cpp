#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int x;
    cin >> n >> x;

    vector<int> luvut;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        luvut.push_back(a);
    }

    map<ll, int> m;
    m[0]++;
    ll summa = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        summa += luvut[i];
        auto it = m.find(summa-x);
        if (it != m.end()) c += it->second;
        m[summa]++;
    }

    cout << c;

    return 0;
}