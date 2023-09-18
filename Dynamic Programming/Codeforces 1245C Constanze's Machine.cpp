/*
 * Problem link: https://codeforces.com/problemset/problem/1245/C
 * Rate: 1400
 * */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int n;
const ll mod = 1e9 + 7;

vector<ll> dp(1e5+1,-1);

ll solve(int index){
    if(index >= n)
        return 1;

    if(dp[index] != -1) return dp[index];

    ll choice1 = 0, choice2;
    if(s[index] == s[index-1]){
        // Assume these two characters (uu/nn) were (w/m) and convert them
        if(s[index] == 'u' || s[index] == 'n')
            choice1 = solve(index + 2);
    }

    // Assume it is correct
    choice2 = solve(index + 1);
    return dp[index] = (choice1 + choice2) % mod;
}

int main(){
    cin >>s;
    n = s.size();

    for (char ch: s) {
        if(ch == 'w' || ch == 'm')
        {
            cout << 0;
            return 0;
        }
    }

    cout << solve(1);
}