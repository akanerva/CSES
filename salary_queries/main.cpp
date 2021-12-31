#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

/**
 * akanerva
 *
 * Tallennetaan päivitetään taulukkoon työntekijän indeksiin hänen palkka.
 *
 * Järjestetään palkat indeksoituun settiin, josta on nopea hakea tiettyyn
 * palkkarangeen kuuluva työntekijöiden määrä.
 *
 */

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //input
    int n, q;
    cin >> n >> q;

    vector<int> luvut(n+1);
    Tree<pair<int,int>> is;
    for (int i = 1; i <= n; i++) {
        cin >> luvut[i];
        is.insert({luvut[i],i});
    }

    //kyselyt
    for (int i = 0; i < q; ++i) {
        char c; int a, b;
        cin >> c >> a >> b;
        if (c == '?') {
            cout << is.order_of_key({b,INT_MAX})-is.order_of_key({a-1,INT_MAX}) << "\n";
        }
        else {
            is.erase({luvut[a],a});
            luvut[a] = b;
            is.insert({luvut[a],a});
        }
    }

    return 0;
}