#include <bits/stdc++.h>

using namespace std;

/**
* https://cses.fi/problemset/task/3220/
*
* Sums of windows don't need to be stored - they can be xorred
* immediately. Otherwise this is a pretty basic moving windows problem.
*
* akanerva
*/

int main() {

  int n, k;
  cin >> n >> k;
  
  if (k > n) {
    cout << 0 << endl;
    return 0;
  }
  
  int x,a,b,c;
  cin >> x >> a >> b >> c;

  vector<unsigned long long int> numbers;
  numbers.push_back(x); 

  // generate numbers according to x,a,b,c
  for (int i = 1; i < n; i++) {
    numbers.push_back((a*numbers[i-1]+b) % c);
  }
  
  // for (auto v : numbers) {
  //   cout << v << ", ";
  // }
  // cout << endl;

  unsigned long long int res;
  unsigned long long int sum = numbers[0];

  // count sum of the initial window
  for (int i = 1; i < k; i++) {
    sum += numbers[i];
  }
  res = sum;
  // cout << res << endl;

  // move window and update sum, then xor sum with res
  unsigned int i = 0;
  unsigned int j = k;
  for (; j < numbers.size(); j++) {
    sum -= numbers[i];
    i++;
    sum += numbers[j];
    res ^= sum;
    // cout << res << endl;
  }

  cout << res << endl;
  
  return 0;

}
