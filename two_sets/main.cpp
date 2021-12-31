#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> S;
    set<int> S2;
    unsigned long long summa = 0;
    for (int i = 1; i <= n; i++) {
        summa += i;
        S.insert(i);
    }


    if (summa % 2 == 1) {
        cout << "NO";
        return 0;
    }
    unsigned long long puoli = summa/2;

    while (summa >= puoli + *S.rbegin()) {
        auto it = --S.end();
        summa -= *it;
        S2.insert(*it);
        S.erase(it);

    }
    unsigned long long ero = accumulate(S.begin(), S.end(), 0) - puoli;

    if (ero > 0) {
        auto it = S.find(ero);
        if (it != S.end()) {
            S2.insert(*it);
            S.erase(it);
        }
        else {
            cout << "upsipupsi!\n";
        }
    }
    cout << "YES\n";
    cout << S.size() << "\n";
    //unsigned long long temp = accumulate(S.begin(), S.end(), 0) % 1000000007;
    //cout << temp << "\n";

    auto it = S.begin();
    for (; it != S.end(); it++) {
        cout << *it << " ";
    }

    cout << "\n";
    cout << S2.size() << "\n";
    //unsigned long long temp2 = accumulate(S2.begin(), S2.end(), 0) % 1000000007;
    //cout << temp2 << "\n";

    auto it2 = S2.begin();
    for (; it2 != S2.end(); it2++) {
        cout << *it2 << " ";
    }


    return 0;
}