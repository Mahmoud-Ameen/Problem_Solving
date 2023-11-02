/*
 * Problem link: https://codeforces.com/problemset/problem/284/A
 * Rating: 1400
 * */

#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

ll comp(ll b, ll e, ll mod){
    if(e == 0) return 1;
    if(e == 1) return b;

    if(e & 1) {
        e--;
        ll temp = comp(b,e/2,mod);
        return ((b * temp) % mod * temp ) % mod;
    }
    ll temp = comp(b,e/2,mod);
    return (temp * temp ) % mod;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        bool isp = true;
        for (int j = 1; j < n-1; ++j) {
            if(comp(i,j,n) - 1 == 0) {
                isp = false;
                break;
            }
        }
        ans+=isp;
    }

    cout << ans << endl;
}