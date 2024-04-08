/*
 * Problem link: https://codeforces.com/contest/1955/problem/D
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
    ll n,m,k;
    cin >> n >> m >>k;
    VI a(n), b(m);
    cin(a);
    cin(b);

    map<int,int> mp;
    for (auto&& i:b)
        mp[i]++;

    int ans = 0;
    map<int,int> curr;
    int matches = 0;
    for (int i = 0; i < m; ++i) {
        if(curr[a[i]] < mp[a[i]]) matches++;
        curr[a[i]]++;
    }

    if(matches >= k) ans++;
    for (int i =1; i + m-1 < n; ++i) {
        if(curr[a[i-1]] <= mp[a[i-1]]) matches--;

        curr[a[i-1]]--;
        curr[a[i+m-1]]++;

        if(curr[a[i+m-1]] <= mp[a[i+m-1]]) matches++;
        if(matches >= k) ans++;
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