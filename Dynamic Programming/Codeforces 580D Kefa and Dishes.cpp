/*
 * Problem link: https://codeforces.com/contest/506/problem/A
 * Rate: 1800
 * Category: Bitmasks
 * */

#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<int> satisfaction;
vector<vector<int>> rules; // rules[prev][i] = raise in satisfaction if prev was eaten directly before i

vector<vector<long long>> memo ( pow(2,18),vector<long long>(19,-1));
long long solve(int mask, int prev){

    if(memo[mask][prev]!=-1) return memo[mask][prev];

    int maskCopy = mask;
    int eaten = 0;
    while(maskCopy){
        if(maskCopy&1) eaten++;
        maskCopy>>=1;
    }
    if(eaten == m) return 0;

    long long solution = 0;
    for (int i = 0; i < n; ++i) {
        if( (mask>>i & 1) == 0) {
            solution = max(solution, satisfaction[i] + rules[prev][i] + solve(mask | (1 << i), i));
        }
    }
    
    return memo[mask][prev] = solution;
}

int main(){
    int k;
    cin >> n>>m>>k;

    satisfaction.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> satisfaction[i];
    }

    rules.resize(n+1,vector<int>(n));
    int x,y,c;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y >> c;
        rules[x-1][y-1] = c;
    }

    cout << solve(0,n);
}