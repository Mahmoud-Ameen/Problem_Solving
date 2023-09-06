/*
 * Problem link: https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029
 * */

#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int maxWeight, vector<int> &profits, vector<int> &weights){

    vector<int>currDp(maxWeight + 1);

    for (int index = 0; index < n; ++index) {
        for (int weight = 0; weight <= maxWeight; ++weight) {
            if(weight >= weights[index])
                max(currDp[weight], currDp[weight-weights[index]] + profits[index]);
        }
    }
    return currDp[maxWeight];
}