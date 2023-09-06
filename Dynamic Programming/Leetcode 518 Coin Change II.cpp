/*
 * Problem Link: https://leetcode.com/problems/coin-change-ii/
 * */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());

        int n = int(coins.size());

        vector<int>currDp(amount+1);

        for (int i = 0; i <= amount; i+=coins[0])
            currDp[i] = 1;


        for (int index = 1; index < n; ++index) {
            int coin = coins[index];
            if(coin > amount) break;
            for (int subAmount = 0; subAmount <= amount; ++subAmount) {
                if(subAmount >= coin)
                    currDp[subAmount]+=currDp[subAmount - coin];
            }
        }

        return currDp[amount];
    }
};