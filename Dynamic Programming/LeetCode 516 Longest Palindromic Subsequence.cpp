/*
 * Problem Link : https://leetcode.com/problems/longest-palindromic-subsequence/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        // STEP 1: Identify the recurrence relation and identify the state

        // LPS("bbbab") = 2 + LPS("bba")
        // LPS("bba") =  max(LPS("ba"),LPS("bb"))

        // LPS(0,4) = 2 + LPS(1,3);           // s[i] equals s[j] && i!=j
        // LPS(1,3) = max(LPS(2,3),LPS(1,2)); // not equal

        // LPS(start,end) = 2 + LPS(start+1,end+1)                 // if s[i] equals s[j] && i!=j
        // LPS(start,end) = max(LPS(start+1,end),LPS(start,end-1)) // not equal

        // STEP 2: Identify base cases
        // LPS of any string of length 1 is 1,
        // LPS of any string of length 2 is 2 if both are equal and 1 otherwise.

        // STEP 3:
        // Start by solving independent sub-problems (Base Cases)
        //      (in this problem substrings with size 1,2)
        // and then the ones depending only on them (substrings with size 3)
        // and go upwards toward the initial big problem (size n)

        int longestPalindromeSubseq(string s) {
        int n = int(s.size());

        vector<int> currentDp(n+1,1);
        vector<int> prevDp(n+1,1);


        for (int i = n-1; i >=0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if(s[i] == s[j] && i!=j){
                    int len = j - i + 1;
                    if(len == 2) currentDp[j] = 2;
                    else currentDp[j] = 2 + prevDp[j-1];

                }
                else currentDp[j] = max(prevDp[j], currentDp[j-1]);

            }
            swap(currentDp,prevDp);
        }

        return prevDp[n-1];
    }
};
