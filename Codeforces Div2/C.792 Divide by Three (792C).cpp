
/*
 * Problem link: https://codeforces.com/problemset/problem/467/C
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>

// Data types/structures
#define ll long long
#define ull unsigned long long
#define V vector
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int,int>
#define PLL pair<ll,ll>

// Loops/ iterators
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fr(a,target) for (int a=0;a<target;a++)
#define frl(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)

// input/output
#define cin(vec) for(auto& ____ : vec) cin >> ____
#define cout(vec) for(auto& ____ : vec) cout << ____ <<" "
#define in(i) int i;cin>>i
#define inl(i) ll i;cin>>i
#define ins(i) string i;cin>>i
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////
#define int ll


void Ma7moud() {
    ins(num);

    int n = (int)num.size();
    int sum = 0;
    fr(i,n) sum += num[i] - '0';


    const int oo = 1e7;
    // i,mod,empty
    V<V<VI>> dp(n+1,V<VI>(3, VI(2,oo)));
    dp[0][0][1] = 0;
    dp[0][0][0] = oo;

    frr(i,1,n+1){
        int digit = num[i-1] - '0';
        frr(mod,0,3){
            dp[i][mod][1] = 1 + dp[i-1][(mod - digit % 3 + 3) % 3][1];
            dp[i][mod][0] = min(1 + dp[i - 1][(mod - digit % 3+3) % 3][0], dp[i-1][mod][0]);
            if(digit != 0 || i == n)
                dp[i][mod][0] = min(dp[i][mod][0], dp[i - 1][mod][1]);

        }
    }

    int ans = min(dp[n][sum%3][0],dp[n][sum%3][0]);
    if(ans < oo){
        string sol;
        int i = n;
        int mod = sum%3;
        int empty = false;

        while(i>0){
        int digit = num[i-1]-'0';
            if(dp[i][mod][empty] == dp[i-1][mod][0]) sol.push_back(num[i-1]);
            else if(dp[i][mod][empty] == dp[i-1][mod][1]) {
                sol.push_back(num[i - 1]);
                break;
            }
            else{
                mod = (mod - digit % 3+3) % 3;
            }
            i--;
        }
        reverse(all(sol));
        cout << sol;
    }
    else if(find(all(num),'0')!=num.end()) cout << 0 <<endl;
    else
        cout << -1 <<endl;
}
// 1000021

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    while(true)
    Ma7moud();
}