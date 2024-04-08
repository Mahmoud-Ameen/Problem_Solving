/*
 * Problem link: https://codeforces.com/contest/1945/problem/B
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
    ll a, b ,c ;
    cin >>a >> b >> c ;

    ll ans = c/a + c/b + 2;

    cout << ans <<endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){

        Ma7moood();
    }
}