/*
 * Problem link: https://codeforces.com/contest/1941/problem/E
 * */

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define cin(vec) for(auto& ____ : vec) cin >> ____
#define cout(vec) for(auto& ____ : vec) cout << ____ <<" "
#define V vector
#define VI vector<int>
#define VLL vector<ll>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fr(a,target) for (int a=0;a<target;a++)
#define frll(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;


void Ma7moood(){
    ll n,m,k,d;
    cin >> n >> m >>k >> d;

    V<VI> depth(n, VI(m));
    for (auto&& v:depth) {
        cin(v);
    }

    VLL rowCost(n);
    for (int row = 0; row < n; ++row) {
        VLL dp(m);

        multiset<ll> mst;
        mst.insert(1);
        dp[0] = 1;
        for (int i = 1; i < m-1; ++i) {
            dp[i] = *mst.begin() + depth[row][i] + 1;
            if(i-d-1 >= 0){
                mst.erase(mst.find(dp[i-d-1]));
            }
            mst.insert(dp[i]);
        }
        rowCost[row] = 1 + *mst.begin();
    }

    ll ans;
    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        sum+=rowCost[i];
    }
    ans = sum;
    for (int i = k; i < n; ++i) {
        sum+=rowCost[i];
        sum-=rowCost[i - k];
        ans = min(sum,ans);
    }

    cout << ans <<endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){

        Ma7moood();
    }
}