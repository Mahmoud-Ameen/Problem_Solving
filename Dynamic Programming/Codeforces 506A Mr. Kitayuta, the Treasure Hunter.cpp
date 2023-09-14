/*
 * Problem link: https://codeforces.com/contest/506/problem/A
 * Rate: 1900
 * */

#include<bits/stdc++.h>
using namespace std;

const int NEGATIVE_INF = -1e9;

int lastGemIsland = 0;
int n;
int start;

vector<int> gems (30000+1);
int dp [30000+1][300];  // DP for positive values of delta
int ndp [30000+1][300]; // DP for negative values of delta

int solve(int island, int delta){
    if(island > lastGemIsland)
        return 0;
    
    if(delta < 0 && ndp[island][-delta] !=-1) return ndp[island][-delta];
    if(delta >= 0 && dp[island][delta] !=-1) return dp[island][delta];

    int choice1 = NEGATIVE_INF,choice2,choice3;

    if(start + (delta-1) > 0) choice1 = solve(island + start + delta - 1,delta - 1);
    choice2 = solve(island + start + delta + 1, delta + 1);
    choice3 = solve(island + start + delta, delta);

    int solution = max({choice1, choice2, choice3}) + gems[island];

    if(delta >= 0) dp[island][delta] = solution;
    else ndp[island][-delta] = solution;

    return solution;
}

int main(){
    cin >> n >> start;
    for (int i = 0; i < n; ++i) {
        int gem;
        cin>> gem;
        gems[gem]++;
        lastGemIsland = max(lastGemIsland,gem);
    }

    memset(dp, -1, sizeof(dp));
    memset(ndp, -1, sizeof(ndp));

    cout << solve(start,0)<<endl;
}