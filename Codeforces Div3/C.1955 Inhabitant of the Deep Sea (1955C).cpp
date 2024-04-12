/*
 * problem link: https://codeforces.com/contest/1955/problem/C
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
#define cyes cout << "YES\n";
#define cno cout << "NO\n";

// Matrix graph traversals
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

void Ma7moood() {
    inl(n) inl(k)
    deque<ll> dq;
    fr(i,n) { in(x) dq.push_back(x); };

    ll ans = 0;
    while(!dq.empty() && k > 0){
        if(dq.size() == 1) {
            if(k >= dq.front()) ans++;
            break;
        }
        ll mn = min(dq.back(),dq.front());
        if (k >= mn * 2){
            dq.back()-=mn;
            dq.front()-=mn;
        }else{
            if(k&1)
                dq.front() -= k / 2 + 1;
            else dq.front() -= k / 2;

            dq.back() -= k / 2;
        }

        k = max(k - mn * 2, (ll)0);

        if(dq.back() == 0) ans++,dq.pop_back();
        if(!dq.empty() && dq.front() == 0) ans++,dq.pop_front();
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        Ma7moood();
    }
}