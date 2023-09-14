/*
 * Problem link: https://codeforces.com/problemset/problem/1272/C
 * Rate: 1200
 * Note that the problem has an easier solution using math.
 * */

#include "bits/stdc++.h"
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    string s;
    cin >> s;

    char key;
    bool keys[30]{false};
    for (int i = 0; i < k; ++i) {
        cin >> key;
        keys[key - 'a'] = true;
    }

    int dp[n+1];
    dp[0] = 0;
    long long count = 0;
    for (int i = 1; i <= n; ++i) {
        if(keys[s[i-1]-'a']) {
            dp[i] = dp[i - 1] + 1;
            count += dp[i];
        }
        else dp[i] = 0;
    }

    cout << count <<endl;
}