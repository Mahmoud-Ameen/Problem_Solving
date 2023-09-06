#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int n, int maxWeight)
{
    vector<int> curr(maxWeight + 1);
    vector<int> prev(maxWeight + 1);

    for (int index = 1; index <= n; ++index) {
        for (int w = 0; w <= maxWeight; ++w) {
            curr[w] = prev[w];
            if(weight[index-1] <= w) {
                int take = value[index - 1] + prev[w - weight[index - 1]];
                if(take > curr[w]) curr[w] = take;
            }
        }
        swap(curr,prev);
    }
    return prev[maxWeight];
}
