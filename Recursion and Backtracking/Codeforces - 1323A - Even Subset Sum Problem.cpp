/**
 * @note: This problem has a much easier and more efficient approach that doesn't require backtracking
 * However, this serves as an exercise on backtracking
 *
 * Problem Link: https://codeforces.com/contest/1323/problem/A
 * */

#include <bits/stdc++.h>

using namespace std;

bool backtrack(int index,int sum,vector<int>& nums,vector<int>& solution){
    // If the sum is even and non-zero, return true
    if(sum %2 == 0 && sum!=0) return true;
    // If all elements have been processed without finding a solution,
    // return false
    if (index == nums.size()) return false;

    // Explore possible solutions that includes this element
    solution.push_back(index);
    if(backtrack(index+1, sum + nums[index], nums, solution)) return true;

    // Explore possible solutions that doesn't include this element
    solution.pop_back();
    if(backtrack(index+1, sum, nums, solution)) return true;

    // If none of the two branches found a solution, return false
    return false;
};

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;

        // Read numbers
        vector<int> nums;
        nums.resize(n);
        for (int i = 0; i < n; ++i) {
            cin>>nums[i];
        }

        vector<int> sol;
        backtrack(0,0,nums,sol);

        // Check if a subset was found and print the result
        if(sol.empty()) cout << "-1" << endl; // No solution found
        else {
            cout << sol.size() << endl;
            for (auto num: sol)
                cout << num + 1 << " ";

            cout <<endl;
        }
    }
}