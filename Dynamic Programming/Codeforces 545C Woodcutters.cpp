/*
 * Problem link: https://codeforces.com/contest/545/problem/C
 * */

#include <bits/stdc++.h>
using namespace std;

vector<int> coords;
vector<int> heights;

vector<vector<int>>dp;

int n;
int recursive(int index,bool prevFallenRight){
    if(index >= n) return 0;

    // Problem already solved
    if(dp[index][prevFallenRight]!=-1) return dp[index][prevFallenRight];

    int option1 = 0, option2 = 0, option3 = 0;
    int currentTreeHeight = heights[index];
    int currentTreePos = coords[index];

    // Cut the tree to fall to the right if possible
    if(index + 1 == n || coords[index+1] > currentTreePos + currentTreeHeight)
        option1 = 1 + recursive(index + 1, true);

    // Cut the tree to fall to the left if possible
    if(index-1 == -1 ||
       (coords[index-1] < currentTreePos - currentTreeHeight && !prevFallenRight) ||
       (coords[index-1] + heights[index-1] < currentTreePos - currentTreeHeight && prevFallenRight))
        option2 = 1 + recursive(index + 1, false);

    // Don't cut the tree
    option3 = recursive(index + 1, false);

    return dp[index][prevFallenRight] = max({option1, option2, option3});
}

int main(){
    cin >> n;

    dp = vector<vector<int>> (n+1,vector<int>(2,-1));

    int x,h;
    for (int i = 0; i < n; ++i) {
        cin >> x>>h;
        coords.push_back(x);
        heights.push_back(h);
    }

    cout << recursive(0,false) << "\n";
}