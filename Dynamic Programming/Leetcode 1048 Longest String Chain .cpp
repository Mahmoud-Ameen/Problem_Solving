//
// Problem link: https://leetcode.com/problems/longest-string-chain/description/
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        int n = words.size();
        int dp[(n+1)];
        for(auto& e: dp) e = 1;

        for(int index = 0; index < n; index++){
            for(int prev = 0 ; prev < index; prev++){
                if(isPredecessor(words[index],words[prev]) && dp[prev] + 1 > dp[index])
                    dp[index] =  1 + dp[prev];
            }
        }
        return *max_element(dp,dp+n);
    }

private:
    bool isPredecessor(string& a,string&  b){
        int i = 0,j = 0,n = a.size(), m = b.size();
        if(n - m !=1) return false;

        while(i < n){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else i++;

        }
        return i == n && j == m;
    }
};