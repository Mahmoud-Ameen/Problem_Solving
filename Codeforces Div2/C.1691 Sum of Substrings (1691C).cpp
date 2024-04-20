/*
 * Problem link: https://codeforces.com/contest/1691/problem/C
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

void Ma7moood() {
    inl(n)
    inl(k)

    ins(s)

    int firstOne = -1,  lastOne = -1;
    for (int i = 0; i < n ; ++i) {
        if(s[i] == '1' && firstOne == -1) firstOne = i;
        if(s[i] == '1') lastOne = i;
    }
    if(firstOne != -1) {
        if (s[n - 1] == '0' && n - 1 - lastOne <= k) {
            for (int i = lastOne; i < n - 1; ++i)
                swap(s[i], s[i + 1]);

            k -= (n - 1 - lastOne);
        }

        if (s[0] == '0' && firstOne <= k && firstOne != n - 1 )
            for (int i = firstOne; i > 0; --i)
                swap(s[i],s[i-1]);
    }
    int ans = 0;
    fr(i,n) {
        if (s[i] == '1') {
            if(i == 0) ans+=10;
            else if(i == n-1) ans+=1;
            else ans+=11;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
    cin >> t;
    while(t--){
        Ma7moood();
    }
}