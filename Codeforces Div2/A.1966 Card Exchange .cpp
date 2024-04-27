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

void Ma7moood() {
    in(n)
    in(k)
    VI a(n);
    cin(a);
    priority_queue<int> pq;
    VI f(150);
    fr(i,n) f[a[i]]++;
    fr(i,150) pq.push(f[i]);

    int ops = 0;
    int b = 0;
    int ans = n;
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        if(x >= k){
            ops+=x/k;
            ans -= x/k;
//            ans += (k-1)*x/k;
            pq.push(x%k);
            b+=(k-1)*(x/k);
        }else if(b >= k - x){
            ops+=1;
            ans -= 1;
            b-= k-x;
            b+=(k)-1;
        }
        else break;
    }
//    while(b>=k)b--;
    cout << ans <<endl;
}

signed main() {
    ios::sync_with_stdio(   false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
    cin >> t;

    while (t--) {
        Ma7moood();
    }
}