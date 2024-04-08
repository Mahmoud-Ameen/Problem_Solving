/*
 * Problem link: https://codeforces.com/contest/1941/problem/B
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
    ll n;
    cin >> n;
    VI a(n);
    cin(a);

    for (int i = 0; i < n-2; ++i) {
        if(a[i] < 0 || a[i+1] < 0 || a[i+2] < 0) return void(cout << "NO\n");
        else{
            a[i+1]-= 2 * a[i];
            a[i+2]-= a[i];
            a[i] = 0;
        }
    }
    if(a[n-1] == 0 && a[n-2] == 0) return void(cout << "YES\n");
    else cout << "NO\n";

}

int main(){
    int t = 1;
    cin >> t;
    while(t--){

        Ma7moood();
    }
}