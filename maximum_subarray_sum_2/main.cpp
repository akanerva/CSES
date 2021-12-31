#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * Käydään taulukko läpi liukuvalla ikkunalla. Lisätään multisettiin rangeen sisältyvät summat
 * ja verrataan maksimia rangen alku -1 indeksiin.
 *
 */


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> luvut; //summataulukko, 1-indeksoitu
    luvut.push_back(0);

    for (int i = 1; i <= n; i++) {
        long long luku;
        cin >> luku;
        luvut.push_back(luku+luvut[i-1]);
    }

    /*
    for (auto luku : luvut) {
        cout << luku << "\n";
    }
    */
    long long res = luvut[a]-luvut[0];
    multiset<long long> summat;

    for (int tail = 1, head = a; tail <= n-a+1; tail++) {

        while (head <= tail+b-1 && head <= n) {
            summat.insert(luvut[head]);
            head++;
        }
        /*
        auto print = summat.begin();
        while (print != summat.end()) {
            cout << *print << " ";
            print++;
        }
        */
        res = max(res, *summat.rbegin()-luvut[tail-1]);
        //cout << " - res = " << res << "\n";
        auto temp = summat.find(luvut[tail+a-1]);
        if (temp != summat.end()) summat.erase(temp);

    }

    cout << res;

    return 0;
}