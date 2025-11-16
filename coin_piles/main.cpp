#include <bits/stdc++.h>

using namespace std;

/**
* https://cses.fi/problemset/task/1754
*
* Three coins are removed on each move, so a+b must be
* divisible by three. Also either pile can't be larger than
* two times the other pile.
*
* akanerva
*/

int main() {

  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    if (a*2 < b || a > b*2 || (a+b) % 3 != 0) {
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
    }
  }

  return 0;
}
