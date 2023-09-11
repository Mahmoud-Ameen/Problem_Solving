/*
 * Problem link: https://codeforces.com/problemset/problem/550/A
 * */

#include <bits/stdc++.h>
using namespace std;

string s;
int n;
// state 0 : searching for AB && BA
// state 1 searching for BA
// state 2 searching for AB
vector<vector<int>> dp;
bool f(int i,int state){
    if(i + 1 >= n) return false;

    if(dp[state][i] != -1) return dp[state][i];

    bool c1 = false ,c3 = false;
    bool c2 = f(i+1,state);
    if((state == 0 || state == 2 ) && (s[i] == 'A' && s[i+1] == 'B')){
        if(state == 2) return dp[state][i] = true;
        c1 = f(i+2,1);
    }
    if((state == 0 || state == 1) && (s[i] == 'B' && s[i+1] == 'A')){
        if(state == 1) return dp[state][i] = true;
        c3 = f(i+2,2);
    }

    return dp[state][i] = c1 || c2 || c3;
}

int main(){
     cin >> s;
     n = s.size();

     dp = vector<vector<int>>(4,vector<int>(n+1,-1));

     cout <<(f(0,0) ? "YES\n" : "NO\n");
}