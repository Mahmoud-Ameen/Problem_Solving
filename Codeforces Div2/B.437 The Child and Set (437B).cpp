/*
 * problem link: https://codeforces.com/contest/437/problem/B
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
#define PII pair<int,int>
#define PLL pair<ll,ll>

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;


void Ma7moood(){
    ll sum, limit;
    cin >> sum >> limit;

    V<PLL> vp;
    while(limit){
        for (ll i = 0; i < 64; ++i) {
            if(limit & (1<<i)) {
                vp.emplace_back(1<<i,limit);
                break;
            }
        }
        limit--;
    }
    sort(rall(vp));
    VLL ans;
    for (auto & i : vp) {
        if(i.first <= sum) {
            ans.push_back(i.second);
            sum-=i.first;
        }
    }
    if(!sum) {
        cout << ans.size() <<endl;
        cout(ans); cout << endl;
    }else cout << -1 <<endl;
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}