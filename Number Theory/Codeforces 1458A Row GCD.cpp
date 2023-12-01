/*
 * Problem link: https://codeforces.com/problemset/problem/1458/A
 * Rating: 1600
 * */

#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define ll long long
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i <<" "
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

using namespace std;

ll gcd (ll x, ll y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<ll> a(n),b(m);
    cin(a);
    cin(b);

    /*
     * gcd(a1,a2,a3,..., an) = gcd(a1,a2-a1,a3-a1,...,an-a1)
     * => gcd(a1+k,a2+k,a3+k,...,an+k) = gcd(a1+k, a2+k-(a1+k), ..., an - (a1+k))
     * = gcd(a1+k, a2 - a1, a3-a1, ..., an-a1)
     * = gcd(a1+k, gcd(a2-a1,a3-a1, ..., an-a1))
     *
     * let gcd(a2-a1,a3-a1, ..., an-a1) = gcdA
     * note that gcdA is a constant value that can be precomputed once and for all
     * */

    ll minElement = *min_element(all(a));
    ll gcdA = 0;

    for (int i = 1; i < n; ++i)
        gcdA = gcd(gcdA, a[i] - minElement);

    for (ll bj: b)
        cout << gcd(minElement + bj, gcdA) << " ";

    cout << endl;
}