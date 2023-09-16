/*
 * Problem link: https://codeforces.com/problemset/problem/1195/C
 * Rate: 1400
 * */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int maxN = 1e5;
vector<int> heights1(maxN+1);
vector<int> heights2(maxN+1);

vector<vector<ll>> dp (maxN+1,vector<ll>(3,-1));

ll solve(int i, int rowNumber){
    if(i == n) return 0;

    if(dp[i][rowNumber] != -1) return dp[i][rowNumber];

    if(rowNumber == 1) return dp[i][rowNumber] =
            max(heights1[i] + solve(i+1,2),
                   solve(i+1,1));

    else  return dp[i][rowNumber] =
            max(heights2[i] + solve(i+1,1),
                   solve(i+1,2));

}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin>> heights1[i];
    for (int i = 0; i < n; ++i)
        cin>> heights2[i];
    cout<<max(solve(0,0), solve(0,1));

}