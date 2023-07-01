/**
 * problem link: https://vjudge.net/problem/UVA-574
 * */

#include <bits/stdc++.h>
using namespace std;


set<vector<int> > result;
void findSums(vector<int>& nums, vector<int>& current, int index, int sum, int target) {

  if (sum == target) {
    result.insert(current);
    return;
  }
  if (index >= nums.size() || sum > target) {
    return;
  }

  // decided to include number
  current.push_back(nums[index]);
    findSums(nums, current, index + 1, sum + nums[index], target);

  // decided to not include number
  current.pop_back();
    findSums(nums, current, index + 1, sum, target);
}

int main() {

  int target, n;
  while (cin >> target) {
    result.clear();

    cin >> n;
    if (target == n && n == 0) break;

    vector<int> nums, current;

    for (size_t i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      nums.push_back(x);
    }
    sort(nums.begin(), nums.end(), greater<int>());

    findSums(nums, current, 0, 0, target);

    cout << "Sums of " << target << ":\n";
    if (result.empty()) cout << "NONE\n";
    else {
        set<vector<int>>::reverse_iterator itr;

        // Displaying elements of the set in reverse
        for (itr = result.rbegin(); itr != result.rend(); itr++) {
            for (int i = 0; i < itr->size(); i++) {
                cout << (*itr)[i];
                if (i != itr->size() - 1) cout << "+";
            }
            cout << "\n";
        }
    }

  }

  return 0;
}