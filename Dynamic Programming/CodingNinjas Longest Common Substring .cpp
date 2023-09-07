#include <bits/stdc++.h>
using namespace std;

int lcs(string& s1, string& s2){
    int sz1 = static_cast<int>(s1.size());
    int sz2 = static_cast<int>(s2.size());

    vector<int> prev(sz2+1);
    vector<int> curr(sz2+1);

    prev[0] = 0;

    int LCS = 0;
    for (int i = 1; i <= sz1; ++i) {
        for (int j = 1; j <= sz2; ++j) {
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
                if(curr[j] > LCS) LCS = curr[j];
            }
            else curr[j] = 0;
        }

        swap(prev,curr);
    }

    return LCS;
}
