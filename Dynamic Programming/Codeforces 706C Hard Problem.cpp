//
// Problem link: https://codeforces.com/contest/706/problem/C
//

#include <bits/stdc++.h>
using namespace std;

vector<string> strings;
vector<int> costs;
int n;

int main(){

    //region Get Input
    cin >> n;
    int c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        costs.push_back(c);
    }
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        strings.push_back(s);
    }
    // endregion

    long long oo = 1e18;
    vector<vector<long long>> dp (n+1,vector<long long>(2,oo));

    dp[0][0] = 0;
    dp[0][1] = costs[0];
    for (int index = 1; index < n; ++index) {
        string current = strings[index];
        string currentReversed = strings[index];
        string prev = strings[index - 1];
        string prevReversed = strings[index - 1];
        reverse(prevReversed.begin(),prevReversed.end());
        reverse(currentReversed.begin(),currentReversed.end());

        // Minimum cost of sorting [0:index] if didn't reverse this one
        {
            if(current >= prev)
                dp[index][0] = dp[index - 1][0];
            if(current >= prevReversed)
                dp[index][0] = min(dp[index][0], dp[index - 1][1]);
        }
        // Minimum cost of sorting [0:index] if reversed this one
        {
            if(currentReversed >= prev)
                dp[index][1] = costs[index] + dp[index - 1][0];
            if(currentReversed >= prevReversed)
                dp[index][1] = min(dp[index][1], costs[index] + dp[index - 1][1]);
        }
    }

    // Output
    long long ans = min(dp[n-1][0],dp[n-1][1]);
    if(ans == oo)
        cout << "-1\n";
    else cout << ans << "\n";

}