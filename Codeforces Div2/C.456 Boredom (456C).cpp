/*
 * Problem link: https://codeforces.com/contest/456/problem/C
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

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
#define in(i) int i;cin>>i;
#define inl(i) ll i;cin>>i;
#define ins(i) string i;cin>>i;
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

// Matrix graph traversals
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

#define int ll

void Ma7moood() {
    in(n)
    VI a(n);
    cin(a);

    VI unique;
    VI value;
    sort(all(a));

    value.push_back(a[0]);
    unique.push_back(a[0]);

    frr(i,1,n){
        if(a[i] == a[i-1]) value.back() += a[i];
        else
            unique.push_back(a[i]),
            value.push_back(a[i]);
    }

    V<VI> dp(unique.size(),VI(2));

    dp[0][1] = value[0]; // Base Case
    frr(i, 1, unique.size()){

        dp[i][0] = max(dp[i-1][1],dp[i-1][0]);

        if(unique[i] == unique[i-1]+1)
            dp[i][1] = value[i] + dp[i-1][0];
        else
            dp[i][1] = value[i] + max(dp[i-1][1],dp[i-1][0]);

    }

    cout << max(dp[unique.size()-1][0],
                dp[unique.size()-1][1]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
//    cin >> t;
    while (t--) {
        Ma7moood();
    }
}