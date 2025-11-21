#include <bits/stdc++.h>

using namespace std;

/**
* https://cses.fi/problemset/task/3359
*
* Naive, initial idea:
* Iterate through the grid left to right, up to bottom.
* Update each cell with the better choice from left or up.
* Straight up string comparison.
*
* Doesn't work though. Way too slow.
*
* Second idea is to only consider right and bottom cells,
* and recursively repeat the process until the end is reached.
* This way there is no need to construct n*n strings of 2n length.
*
* akanerva
*/


void solve(int& n, vector<string>& grid, vector<char>& dp ) {

  // 1d array
  vector<vector<bool>> included(n, vector<bool>(n, false));
  included[0][0] = true;
  
  dp[0] = grid[0][0];
  vector<char> diag(6000,'[');
  // go through diagonals
  for (int k = 0; k < 2*n-1; k++) {
    int i = min(k,n-1);
    int j = k-i;
    char minChar = '[';
    // map min char for each diagonal
    while (i >= 0 && j < n) {
      if (included[i][j]) minChar = min(minChar, grid[i][j]);
      i--; j++;
    }
    i = min(k,n-1);
    j = k-i;
    dp[k] = minChar;
    // expand every min char that's not excluded
    while (i >= 0 && j < n) {
      if (included[i][j]) {
        // include cells on right and bottom
        if (i+1 < n && grid[i][j] == minChar) included[i+1][j] = true;
        if (j+1 < n && grid[i][j] == minChar) included[i][j+1] = true;
      }
      i--; j++;
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<string> grid;
  for (int i = 0; i < n; i++) {
    string str; cin >> str;
    grid.push_back(str);
  }

  vector<char> dp(6000, '[');
  solve(n, grid, dp);

  for (int i = 0; i < 2*n-1; i++) {
    cout << dp[i];
  }
  cout << endl;

  return 0;
}
