/*
 * Problem link: https://leetcode.com/problems/longest-common-subsequence/
 * */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int longestCommonSubsequence(const string& text1, const string& text2) {
        int sz1 = int(text1.size());
        int sz2 = int(text2.size());

        vector<int> currentDp(sz2+1);
        vector<int> prevDp(sz2+1);

        for (int i = 1; i <= sz1; ++i) {
            for (int j = 1; j <= sz2; ++j) {
                if(text1[i-1] == text2[j-1]){
                    currentDp[j]= 1 + prevDp[j-1];
                }
                else
                    currentDp[j] = max(currentDp[j-1],prevDp[j]);
            }
            swap(prevDp,currentDp);
        }

        return *max_element(prevDp.begin(),prevDp.end());
    }
};
