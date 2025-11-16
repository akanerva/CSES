#include <bits/stdc++.h>

using namespace std;

/**
* https://cses.fi/problemset/task/3399
*
* nk always wins nk-1. To achieve the most amount of points,
* play nk vs nk-1 n-1 times, then lose once. So, max points
* available for one player is n-1.
*
* Zero points for a player is only possible if the other player
* also has exactly zero points.
*
* Having the losing player's line always equal 1,2,...,n made
* this somewhat more simple, at least for me.
*
* akanerva
*/


int main() {

  int t; cin >> t;

  vector<int> n,a,b;

  for (int i = 0; i < t; i++) {
    int x,y,z; cin>>x>>y>>z;
    n.push_back(x);
    a.push_back(y);
    b.push_back(z);
  }

  for (int j = 0; j < t; j++) {

    // check for 0 points
    if ((a[j] == 0 || b[j] == 0) && a[j] != b[j]) {
      cout << "NO" << endl;
      continue;
    }

    // check for too many points for one player
    if (a[j] > n[j]-1 || b[j] > n[j]-1) {
      cout << "NO" << endl;
      continue;
    } 
    
    // check for a legal sum of points
    if (a[j]+b[j] > n[j]) {
      cout << "NO" << endl;
      continue;
    }

    // check for too many total points
    if (a[j]+b[j] > n[j]) {
      cout << "NO" << endl;
      continue;
    }
 
    vector<int> winning;

    int more = max(a[j], b[j]);
    int less = min(a[j], b[j]);
    // values that win
    for (int i = less+1; i < less+1+more; i++) {
      winning.push_back(i);
    }

    // values that lose
    for (int i = 1; i <= less; i++) {
      winning.push_back(i);
    } 

    // values that tie
    for (int i = a[j]+b[j]+1; i <= n[j]; i++) {
      winning.push_back(i);
    }

    
    cout << "YES" << endl;
    if (a[j] >= b[j]) {
      for (auto v : winning) {
        cout << v << " ";
      }
      cout << endl;
    }

    // losing line is always 1,2,3,...,n
    for (int i = 1; i <= n[j]; i++) {
      cout << i << " ";
    }
    cout << endl;

    if (a[j] < b[j]) {
      for (auto v : winning) {
        cout << v << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
