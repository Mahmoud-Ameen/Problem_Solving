/*
 * Problem link: https://codeforces.com/problemset/problem/1154/F
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
#define in(i) int i;cin>>i
#define inl(i) ll i;cin>>i
#define ins(i) string i;cin>>i
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////
#define int ll

int dp[1002][1002];
int choice[1002][1002] = {-1};
char chs[1002][1002];

string a,b;
int n,m;

int solve(int i, int j){
    if (i == n) return m-j;
    if (j == m) return n-i;

    if(a[i] == b[j]) return solve(i+1,j+1);

    int& ret = dp[i][j];
    if(~ret) return ret;

    int insert = 1 + solve(i,j+1);
    int replace = 1 + solve(i+1,j+1);
    int del = 1 + solve(i+1,j);

    if(replace <= insert && replace <= del) choice[i][j] = 1;
    else if(insert <= replace && insert <= del) choice[i][j] = 2;
    else  choice[i][j] = 3;

    return ret = min({insert,replace,del});
}

void Ma7moud() {
    memset(dp,-1,sizeof(dp));
    cin>>a;
    cin >> b;
    n = a.size(),m = b.size();


    cout << solve(0,0) << endl;

    int i = 0,j = 0;
    while(!(i==n||j==m)){
        if(a[i]==b[j]) i++,j++;
        else if(choice[i][j] == 1) cout << "REPLACE "<< j+1 << " " << b[j] <<endl,i++,j++;
        else if(choice[i][j] == 2) cout << "INSERT "<< j+1 << " " << b[j] <<endl,j++;
        else if(choice[i][j] == 3) cout << "DELETE "<< j+1 << endl,i++;
    }
    while(i!=n)cout << "DELETE "<< j+1 << endl,i++;
    while(j!=m)cout << "INSERT "<< j+1 << " " << b[j] <<endl,j++;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    Ma7moud();
}