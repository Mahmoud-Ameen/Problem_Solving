/*
 * Problem link: https://codeforces.com/problemset/problem/1042/B
 * Rate: 1700
 * */

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e8;
int k1,k2;

// dp[n1][n2][width][prevWasFootman]
vector<vector<vector<vector<long long>>>> dp(101,vector<vector<vector<long long>>>(101,vector<vector<long long>>(11,vector<long long>(2,-1))));

long long solve(int n1, int n2,int width, bool prevWasFootman){
    if(n1 == 0 && n2 == 0)
        return 1;

    if(n1 < 0 || n2 < 0) return 0;

    if(dp[n1][n2][width][prevWasFootman] != -1) return dp[n1][n2][width][prevWasFootman];

    // ChoiceF : Number of ways if placed a Footman in this place
    // ChoiceH : Number of ways if placed a Horseman in this place
    long long choiceF = 0, choiceH = 0;

    if (prevWasFootman) {
        choiceH = solve(n1, n2 - 1, 1, false);
        if(width < k1)
            choiceF = solve(n1 - 1, n2, width + 1, true);
    }

    if (!prevWasFootman) {
        choiceF = solve(n1 - 1, n2, 1, true);
        if(width < k2)
            choiceH = solve(n1, n2 - 1, width + 1, false);
    }

    return dp[n1][n2][width][prevWasFootman] = (choiceH + choiceF) % mod;
}

int main(){
    int n1,n2;
    cin>> n1 >> n2 >> k1 >> k2;

    cout << (solve(n1-1, n2,1,true) + solve(n1,n2-1,1,false)) % mod;
}