/*
 * Problem link: https://codeforces.com/contest/270/problem/D.
 * Rate: 1700?
 * */

#include <bits/stdc++.h>
using namespace std;

// Longest Increasing subsequence
int lis(vector<int>& arr){
    int n = int(arr.size());

    vector<int> dp(n,1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(arr[i] >= arr[j])
                dp[i] = max(dp[i],1+dp[j]);
        }
    }

    return *max_element(dp.begin(),dp.end());
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> plants (n);
    for (int i = 0; i < n; ++i) {
        double x;
        cin >>plants[i]>>x;
    }
    cout << n - lis(plants) << endl;
}