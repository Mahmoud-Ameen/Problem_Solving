/*
 * Problem link: https://codeforces.com/problemset/problem/735/D
 * Rating: 1600
 * */

#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define ll long long
#define ull unsigned long long
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i <<" "
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

using namespace std;

ll gcd (ll x, ll y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

ll lcm(ll x, ll y){
    return x * y / (gcd(x,y));
}
ll lcmTriple(ll x,ll y, ll z){
    return lcm(lcm(x,y),z);
}

int main(){
    ll n;
    cin >> n;
    if(n == 1) cout << 1;
    else if(n == 2) cout << 2;
    else {
        ll mx = 0;
        for (int i = 0; i < min(n,10ll); ++i) {
            for (int j = i; j < min(n,10ll); ++j) {
                for (int k = j; k < min(n,10ll); ++k) {
                    mx = max(mx, lcmTriple(n-i,n-j,n-k));
                }
            }
        }
        cout << mx <<endl;
    }
    cout << endl;
}
