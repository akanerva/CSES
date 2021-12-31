#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> orderedMultiset;
typedef long long ll;

/**
 * akanerva
 * Lasketaan uusi cost dynaamisesti.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> luvut;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        luvut.push_back(a);
    }

    orderedMultiset ms;
    auto median = [&]() { return (k&1) ? *ms.find_by_order(k/2) : (*ms.find_by_order(k/2-1) + *ms.find_by_order(k/2-1))/2; };

    for (int i = 0; i < k; i++) {
        ms.insert(luvut[i]);
    }

    int mdval = median();
    ll cost = 0;
    for (auto a : ms) {
        cost += abs(mdval-a);
    }
    cout << cost << " ";

    for (int i = k; i < n; i++) {
        ms.erase(ms.upper_bound(luvut[i-k]));
        ms.insert(luvut[i]);
        int newmdval = median();
        cost += abs(newmdval-luvut[i]) - abs(mdval-luvut[i-k]);
        if (k%2 == 0) cost -= (newmdval - mdval);
        mdval = newmdval;
        cout << cost << " ";
    }

    return 0;
}