/*
 * problem link: https://codeforces.com/contest/88/problem/C
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
int gcd (int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}
void Ma7moood(){
    ll a,b;
    cin >> a >> b;

    if(gcd(a,b) == max(a,b) - min(b,a)) cout << "Equal\n";
    else if(a < b){
        cout << "Dasha\n";
    }else{
        cout << "Masha\n";
    }
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}