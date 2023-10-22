//
// Created by MAHMOUD on 10/22/2023.
//
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> prices(1005);
vector<int> weights(1005);
vector<vector<int>> memo (31,vector<int>(1005));

int solve(int weight,int productIndex){
    if(productIndex == n) return 0;

    if(memo[weight][productIndex] != -1) return memo[weight][productIndex];

    int take = 0,leave = 0;
    if(weights[productIndex] <= weight)
        take = prices[productIndex] + solve(weight-weights[productIndex],productIndex+1);
    leave = solve(weight,productIndex+1);

    return memo[weight][productIndex] = max(take,leave);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >>n;
        for (int i = 0; i < 31; ++i)
            for (int j = 0; j < 1005; ++j)
                memo[i][j] = -1;


        for (int i = 0; i < n; ++i)
            cin>>prices[i] >> weights[i];


        int group, personMaxWeight;
        cin >> group;
        int maxVal = 0;
        for (int i = 0; i < group; ++i) {
            cin >> personMaxWeight;
            maxVal+=solve(personMaxWeight, 0);
        }

        cout << maxVal << endl;
    }
}