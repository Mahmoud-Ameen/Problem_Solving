/*
 * Problem link: https://codeforces.com/contest/1966/problem/A
 * */

#include <bits/stdc++.h>

// Data types/structures
#define ll long long
#define ull unsigned long long
#define V vector
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int,int>
#define PLL pair<ll,ll>

// Loops/ iterators
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fr(a,target) for (int a=0;a<target;a++)
#define frl(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)

// input/output
#define cin(vec) for(auto& ____ : vec) cin >> ____
#define cout(vec) for(auto& ____ : vec) cout << ____ <<" "
#define in(i) int i;cin>>i;
#define inl(i) ll i;cin>>i;
#define ins(i) string i;cin>>i;
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

// Matrix graph traversals
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

int N = 3e4+15;
V<int> gems(N+50);
V<VI> dp(N+500,VI(605,-1));
int start;
int solve(int island,int delta){
    if(island > N ) return 0;

    if(dp[island][delta+300]!=-1) return dp[island][delta+300];

    int next1 = island + start + (delta);
    int next2 = island + start + (delta) + 1;
    int next3 = island + start + (delta) - 1;

    int c1 = 0,c2= 0,c3= 0;
    if(next1 > island )
        c1= solve(next1, delta);
    if(next2 > island)
        c2= solve(next2,delta + 1);
    if(next3 > island)
        c3= solve(next3,delta - 1);

    return dp[island][delta+300] = max({c1,c2,c3}) + gems[island];
}

void Ma7moood() {

    in(n)
    in(d)

    fr(i,n){
        in(x)
        gems[x]++;
    }

    start = d;
    cout <<solve(d,0)<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
//    cin >> t;

    while (t--) {
        Ma7moood();
    }
}