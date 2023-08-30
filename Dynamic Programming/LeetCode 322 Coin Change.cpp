#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        int oo = numeric_limits<int>::max() - 1;
        vector<int>dp(amount+1,oo);

        for (int& coin: coins) {
            if(coin > amount) continue;
            dp[coin] = 1;
        }
        dp[0] = 0;

        // Build DP using Bottom-Up Method
        for (int i = 1; i <= amount; ++i) {
            for (auto &coin : coins) {
                if(coin <= i) {
                    dp[i] = min(dp[i], dp[coin] + dp[i - coin]);
                }
            }
        }

        // dp[amount] == oo means that no solution was found
        return ( dp[amount] == oo ? -1 : dp[amount]);
    }
};
