/*
 * Problem link: https://codeforces.com/contest/255/problem/C
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

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
#define int ll
void Ma7moood() {
    in(n) in(m) in(x) in(y)

    V<string> g(n);
    cin(g);

    V<VI> colorNum(2,VI(m));
    fr(i,m) fr(j,n)
        if (g[j][i] == '.') colorNum[0][i]++;
        else colorNum[1][i]++;

    // col, previousGroupWidth, previousGroupColor
    V<V<VI>> dp(m,V<VI>(y+1,VI(2,1e7)));
    frr(width,0,y+1){
        fr(color,2){
            if(width == 0) dp[0][width][color] = min(colorNum[0][0],colorNum[1][0]);
            else if(width == x-1 ){
                dp[0][width][color] = colorNum[color][0];
            }
            else if(width == y){
                dp[0][width][color] = colorNum[1-color][0];
            }
            else if(width >= x){
                if(x==1)
                    dp[0][width][color] = min(colorNum[1-color][0],colorNum[color][0]);
                else dp[0][width][color] = colorNum[color][0];
            }
        }
    }
    frr(col,1,m){
        frr(width,0,y+1){
            fr(color,2){
                if(width == 0) dp[col][width][color] = min(
                        dp[col-1][1][0] + colorNum[0][col],
                        dp[col-1][1][1] + colorNum[1][col]);
                else if(width < x){
                    dp[col][width][color] = dp[col-1][width+1][color] + colorNum[color][col];
                }
                else if(width == y){
                    dp[col][width][color] = dp[col-1][1][1-color] + colorNum[1-color][col];
                }
                else {
                    dp[col][width][color] = min(dp[col-1][width+1][color] + colorNum[color][col],
                                                dp[col-1][1][1-color] + colorNum[1-color][col] );
                }
            }
        }
    }

    cout << min(dp[m-1][0][0],dp[m-1][0][1]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
    while (t--) {
        Ma7moood();
    }
}