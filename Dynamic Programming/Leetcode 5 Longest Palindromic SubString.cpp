/*
 * Problem Link: https://leetcode.com/problems/longest-palindromic-substring/
 * */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = int(s.size());

        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        for (int i = 0; i <= n; ++i) {
            dp[i][i] = true;
        }

        int lpsLength=1; /*longest palindromic substring length*/
        int lpsStart=0;  /*start index of longest palindromic substring length*/
        for (int start = n-1; start >= 0; --start) {
            for (int end = n-1; end >= 0; --end) {
                if(s[start] == s[end] &&
                (end - start < 1 /* No elements in between */ ||
                dp[start+1][end-1] /* Elements in between are palindromic */ )){
                    dp[start][end] = true;
                    int currentLength = end - start + 1;
                    if(currentLength > lpsLength){
                        lpsLength = currentLength;
                        lpsStart = start;
                    }
                }else{
                    dp[start][end] = false;
                }
            }
        }

        string res;
        for (int i = lpsStart; i < lpsStart+lpsLength; ++i) {
            res.push_back(s[i]);
        }
        return res;
    }
};