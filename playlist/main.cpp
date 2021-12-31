#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 * Iteroidaan lukujen läpi päällä ja hännällä.
 *
 */
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> input;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }

    int msf = 0;
    set<int> luvut;
    luvut.insert(input[0]);

    for (auto tail = input.begin(), head = input.begin(); next(tail) != input.end(); tail++) {
        while (next(head) != input.end() && luvut.count(*next(head)) == 0) {
            head++;
            luvut.insert(*head);
            msf = max(msf, (int)distance(tail, head)+1);
        }

        luvut.erase(*tail);
    }

    cout << msf;

    return 0;
}