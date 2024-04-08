/*
 * Problem link: https://codeforces.com/contest/1945/problem/C
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
    int n;
    cin >> n ;
    string s; cin >> s;

    VI left(n), right(n);
    for (int i = 0; i < n; ++i) {
        if(s[i] == '0') left[i]++;
        else right[i]++;
    }

    // prefix sum of people who want to stay on left
    for (int i = 1; i < n; ++i)
        left[i] += left[i - 1];

    // suffix sum of people who want to stay on right
    for (int i = n-2; i >=0 ; --i)
        right[i]+=right[i + 1];


    double d = 1e8; // distance from center
    ll ans = -1;
    for (int i = 0; i < n; ++i) {
        if((left[i] * 2 >= i + 1 ) && (i == n - 1 || right[i + 1] * 2 >= n - i - 1)) {
            if(abs((n)/2.0 - i - 1) < d){
                d = abs((n)/2.0 - i - 1);
                ans = i;
            }
        };
    }

    // road before first house
    if(right[0] * 2 >= n && abs((n) / 2.0 ) <= d)
        ans = -1;


    cout << ans + 1 <<endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){

        Ma7moood();
    }
}