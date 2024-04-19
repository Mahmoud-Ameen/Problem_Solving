/*
 * Problem link: https://codeforces.com/contest/253/problem/C
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
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};


using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

V<map<int,int>> dist;
VI len;
int bx,by,n;
int mn = 1e8;
void f(int x, int y, int cost){
    if(dist[y].find(x) != dist[y].end() && dist[y][x] <= cost) return;
    dist[y][x] = cost;

    if(y != n)  // down
        f(min(x,len[y+1]+1),y+1,cost+1);

    if(y != 1)  // up
        f(min(x,len[y-1]+1),y-1,cost+1);

    if(y == by) mn = min(mn,abs(bx - x) + cost);
}

void Ma7moood() {
    cin >> n;
    len = VI(n);
    cin(len);

    len.insert(len.begin(),0);
    dist = V<map<int,int>>(n + 1);

    in(y)
    in(x)
    cin >> by >> bx;

    f(x,y,0);
    cout << mn <<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}