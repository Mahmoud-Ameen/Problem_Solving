/*
 * problem link: https://codeforces.com/contest/371/problem/B
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
    int a,b;
    cin >> a >> b;

    // index 0: how many twos
    // index 1: how many threes
    // index 2: how many fives
    VI aFactors(4),bFactors(4);
    while(a%2==0)aFactors[0]++,a/=2;
    while(a%3==0)aFactors[1]++,a/=3;
    while(a%5==0)aFactors[2]++,a/=5;

    while(b%2==0)bFactors[0]++,b/=2;
    while(b%3==0)bFactors[1]++,b/=3;
    while(b%5==0)bFactors[2]++,b/=5;

    if(a != b) return void(cout << "-1\n");

    int ans = 0;
    for (int i = 0; i < 3; ++i)
        ans+=abs(aFactors[i]-bFactors[i]);

    cout << ans <<endl;
}


int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}