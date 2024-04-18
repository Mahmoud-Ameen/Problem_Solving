/*
 * Problem link: https://codeforces.com/contest/486/problem/C
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

    // 010 1010010
    // x | y
    // go to smaller, then go back

    in(n)
    in(p)

    ins(s);
    VI a(n/2);
    ll ans = 0;
    int first = -1;
    int last = -1;
    // split the string in halves and
    fr(i,n/2){
        if(s[i] != s[n-1-i]) {
            ans += min((s[i] - s[n - 1 - i] + 26) % 26, (s[n - 1 - i] - s[i] + 26) % 26), a[i] = 1;

            // find index of first and last chars needing to change
            if(first == -1) first = i;
            last = i;
        }
    }

    p--; // use zero based indexing

    // if p is in the second half, map it to the corresponding index in first half
    if(p > (n-1)/2)
        p = n-1-p;

    if(first == -1) cout << ans; // Already palindrome
    else{
        // there exist elements to the right and elements to the left which needs changes
        if(last >= p && first <= p)
            ans += 2*min(p-first,last-p) + max(p-first,last-p);

        // all changes are to one direction
        else ans+=max(abs(p-first),abs(last-p));
        cout << ans;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}