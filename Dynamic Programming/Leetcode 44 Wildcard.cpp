/*
 * Problem link: https://leetcode.com/problems/wildcard-matching/
 * */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = int(s.size());
        int m = int(p.size());

        vector<short> currDp (m+1);
        vector<short> prevDp (m+1);

        prevDp[0] = true;

        for (int j = 1; j <= m; ++j)
            if(p[j-1] == '*') prevDp[j] = prevDp[j-1];

        for (int i = 1; i <= n; ++i) {
            currDp[0] = false;
            for (int j = 1; j <= m; ++j) {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    currDp[j] = prevDp[j - 1];

                else if(p[j-1] == '*')
                    currDp[j] = prevDp[j - 1]
                                || currDp[j - 1]
                                || prevDp[j];

                else currDp[j] = false;

            }
            swap(currDp,prevDp);
        }
        return prevDp[m];
    }
};
