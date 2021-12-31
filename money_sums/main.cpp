#include <bits/stdc++.h>

using namespace std;

const int dpN = 1e5;
bool dp[dpN+1];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int kolikko;
        cin >> kolikko;
        sum += kolikko;
        c.push_back(kolikko);
    }

    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (dp[j]) {
                dp[j+c[i]] = true;
            }
        }
    }

    set<int> summat;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            summat.insert(i);
        }
    }

    cout << summat.size() << "\n";
    for (auto &a : summat) {
        cout << a << " ";
    }



    return 0;
}