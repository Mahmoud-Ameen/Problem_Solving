#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Longest common subsequence

        int sz1 = static_cast<int>(word1.size());
        int sz2 = static_cast<int>(word2.size());

        vector<int> prevDp(sz2+1,0);
        vector<int> currDp(sz2+1,0);
        for (int i = 0; i < sz1; ++i) {
            for (int j = 0; j < sz2; ++j) {
                if(word1[i] == word2[j])
                    currDp[j] = 1 + (j > 0 ?  prevDp[j-1] : 0);
                else
                    currDp[j] = max(prevDp[j],(j > 0 ? currDp[j-1] : 0));
            }
            swap(prevDp,currDp);
        }

        return (sz1 - prevDp[sz2-1]) + (sz2 - prevDp[sz2-1]);
    }

};
