#include <bits/stdc++.h>

using namespace std;

/**
* https://cses.fi/problemset/task/3420
*
* Moving "windows" - i left, j right. Track when duplicates
* are encountered with the help of a set. Increment i and
* add subarrays starting from the old i, until i to j subarray
* has no duplicates.
*
* akanerva
*/

int main() {
  int n; cin >> n;
  vector<unsigned long long int> numbers;

  for (int i = 0; i < n; i++) {
    unsigned long long int temp; cin >> temp;
    numbers.push_back(temp);
  }

  unsigned long long int res = 0;
  for (unsigned int i = 0; i < numbers.size(); i++) {
    set<int> helpSet;
    for (unsigned int j = i; j < numbers.size(); j++) {
      if (helpSet.find(numbers[j]) != helpSet.end()) {
        while (true) {
          helpSet.erase(numbers[i]);
          if (numbers[i] == numbers[j]) {
            // cout << j-i << endl;
            res += j-i;
            i++;
            break;
          }
          // cout << j-i << endl;
          res += j-i;
          i++;
        }
      }
      if (j == numbers.size()-1) {
        unsigned long long int temp = j-i+1;
        // cout << (temp*temp+temp)/2 << endl;
        res += (temp*temp+temp)/2;
        i = numbers.size();
        break;
      }
      helpSet.insert(numbers[j]);
    }
  }

  cout << res << endl;
  return 0;
}
