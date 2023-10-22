/*
 * Problem Link: https://vjudge.net/problem/UVA-10131
 * */

#include <bits/stdc++.h>
using namespace std;

int main() {

    int weight, iq, id = 1;
    vector<pair<pair<int,int>,int>> elephants;

    while (cin >> weight >> iq){
        elephants.push_back({{weight, iq},id++});
    }
    sort(elephants.begin(),elephants.end());
    
    // Longest decreasing subsequence
    int n = int(elephants.size());
    vector<int> dp(n,1);
    vector<int> traceback(n,-1);

    for (int i = 0; i < n; ++i) {
        for (int prev = 0; prev < i; ++prev) {
            if(elephants[i].first.second < elephants[prev].first.second){
                if(1 + dp[prev] > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    traceback[i] = prev;
                }
            }
        }
    }

    // get last element in longest sequence
    int index = -1;
    int longest = -1;
    for (int i = 0; i < n; ++i) {
        if(dp[i] > longest) {
            longest = dp[i];
            index = i;
        }
    }

    // build Output
    stack<int> path;
    while(index!=-1){
        path.push(elephants[index].second);
        index = traceback[index];
    }

    // output
    cout << longest << endl;
    while(!path.empty()){
        cout << path.top() << endl;
        path.pop();
    }
}