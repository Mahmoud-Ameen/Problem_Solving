/*
 * Problem link: https://vjudge.net/problem/UVA-10192
 * */

#include <iostream>
#include <vector>
#include <algorithm>

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

signed main() {
    VI dp;
    VI prev;
    int t = 1;
    while (true) {
        string a,b;
        getline(cin,a);

        if(a[0] == '#') return 0;
        getline(cin,b);

        int n = (int)a.size();
        int m = (int)b.size();

        dp.resize(m+1);
        prev.resize(m+1);
        fr(j,m+1) dp[j] = prev[j] = 0;

        frr(i,1,n+1){
            frr(j,1,m+1){
                if(a[i-1] == b[j-1]) dp[j] = prev[j-1] + 1;
                else dp[j] = max(prev[j],dp[j-1]);
            }
            swap(dp,prev);
        }
        cout << "Case #"<<t<<": you can visit at most "<<prev[m]<<" cities." << endl;
        t++;
    }
}