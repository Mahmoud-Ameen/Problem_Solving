//
// Problem link: https://vjudge.net/problem/UVA-374
//

#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

ll expMod(ll base, ll exp, ll mod){
    if(exp == 0) return 1;
    if(exp == 1) return base;

    if(exp & 1){
        exp--;
        ll temp = expMod(base,exp/2, mod);
        return ((base * temp) % mod * temp) % mod;
    }
    ll temp = expMod(base,exp/2, mod);
    return (temp * temp) % mod;
}

int main(){
    ll b, p, m;
    while(cin >> b >> p >> m){
        cout << expMod(b,p,m) << endl;
    }
}