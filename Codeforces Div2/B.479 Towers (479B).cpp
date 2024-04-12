/*
 * problem link: https://codeforces.com/contest/479/problem/B
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
#define frl(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)
#define PII pair<int,int>
#define PLL pair<ll,ll>

#define in(i) int i;cin>>i;
#define inl(i) ll i;cin>>i;
#define ins(i) string i;cin>>i;

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;


void Ma7moood() {
    in(n) in(k)

    V<PII> v;
    fr(i,n){
        in(x);
        v.emplace_back(x, i+1);
    }

    V<PII> op;
    while(k){
        PII& x = *max_element(all(v));
        PII& y = *min_element(all(v));

        if (x.first - y.first <= 1) break;

        x.first--, y.first++;
        op.emplace_back(x.second,y.second);
        k--;
    }

    cout << max_element(all(v))->first - min_element(all(v))->first << " " << op.size()  <<endl;
    for (auto & i : op) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}