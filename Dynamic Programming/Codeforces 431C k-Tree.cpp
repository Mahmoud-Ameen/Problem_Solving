/*
 * Problem link: https://codeforces.com/contest/101/problem/B
 * Rate: 1600
 * Category: Basic Counting Dp
 * */

#include <bits/stdc++.h>
using namespace std;

int k;
int d;
int target;
const int mod = 1e9+7;

vector<vector<vector<long long>>> dp(101,vector<vector<long long>>(101,vector<long long>(2,-1)));
long long solve(int i, int sum, bool conditionMet){
    if(sum == target) return conditionMet;
    if(i > k || sum > target) return 0;

    if(dp[i][sum][conditionMet] != -1) return dp[i][sum][conditionMet];

    return dp[i][sum][conditionMet] = solve(i + 1, sum, conditionMet) % mod + solve(1, sum + i, conditionMet || (i >= d) % mod);
}

int main(){
    cin>>target>>k>>d;
    cout <<solve(1,0,false) % mod;
}