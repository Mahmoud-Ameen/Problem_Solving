/*
 * Problem link: https://codeforces.com/problemset/problem/1380C
 * Rate: 1400
 * */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nINF = -1e9;

vector<int> programmers(1e5 + 5);
vector<int> dp(1e5+1);

int n,x;
int solve(int idx){

    if(idx == n )
        return 0;
    if(idx > n) return nINF;

    if(dp[idx] != -1) return dp[idx];

    // Number of members in this team if programmers[idx] is the programmer with the
    // least skill in the team
    int members = ceil(double(x) / programmers[idx]);

    return dp[idx] = max(
            1 + solve(idx + members), // create programmers team with this programmer
               solve(idx + 1) // don't put this noob in a team
               );
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin >> n>>x;
        for (int i = 0; i < n; ++i) {
            cin >> programmers[i];
        }

        fill(dp.begin(),dp.begin()+n,-1); // reset dp
        std::sort(programmers.begin(), programmers.begin() + n);

        cout << solve(0)<<endl;
    }
}