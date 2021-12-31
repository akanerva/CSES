#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> orderedMultiset;

/**
 * akanerva
 * Eka kerta kun käytän g++ -funktiota, tietääkseni.
 * Ordered_multiset toimi tähän just hyvin.
 * md ehkä ihan vaan floor(k/2) ?
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

    for (int i = 0; i < k; i++) {
        ms.insert(luvut[i]);
    }

    int md = ceil((double)k/2)-1;
    cout << *ms.find_by_order(md) << " ";

    for (int i = k; i < n; i++) {
        ms.erase(ms.upper_bound(luvut[i-k]));
        ms.insert(luvut[i]);
        cout << *ms.find_by_order(md) << " ";
    }

    return 0;
}