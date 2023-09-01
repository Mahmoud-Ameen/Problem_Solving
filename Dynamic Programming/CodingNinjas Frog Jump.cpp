/*
 * Problem Link: https://www.codingninjas.com/studio/problems/frog-jump_3621012/
 * */

#include <bits/stdc++.h>

using namespace std;

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n);
    for (int index = n-2; index >= 0; --index) {
        int oneJump = abs(heights[index+1] - heights[index]) + dp[index+1];
        int twoJumps = INT_MAX;

        if(index + 2 < n)
            twoJumps = abs(heights[index+2] - heights[index]) + dp[index+2];

        dp[index] = min(oneJump,twoJumps);
    }

    return dp[0];
}

int main(){
    vector<int> v{10,20,30, 10};
    cout << frogJump(4,v);
}

