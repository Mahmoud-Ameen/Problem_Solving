/*
 * problem link: https://codeforces.com/contest/371/problem/C
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
    string s;
    cin >> s;

    ll nb,ns,nc,pb,ps,pc;
    cin >> nb >> ns >> nc
        >> pb >> ps >> pc;

    ll r;
    cin >> r;

    ll ndb = 0,ndc = 0,nds = 0;
    for (char& ch:s) {
        if(ch == 'B')ndb++;
        else if(ch == 'S')nds++;
        else ndc++;
    }

    ll hams = 0;

    // Binary search for largest number of hams that can be made
    ll st = 0, end = 1e13;

    while(st <= end){
        ll md = (st+end)/2;
        ll cost = md * (ndb*pb + ndc * pc + nds * ps);
        cost -= min(nb, md*ndb) * pb;
        cost -= min(nc, md*ndc) * pc;
        cost -= min(ns, md*nds) * ps;

        if(cost > r) end = md - 1;
        if(cost <= r) {
            hams = max(hams,md);
            st = md + 1;
        }
    }

    cout << hams << endl;
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}