//
// Created by MAHMOUD on 4/18/2024.
//
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

set<int> removed;
V<string>ss;

void f(int st,int end,int col) {
    if(col == ss[0].size()) return;
    if(removed.count(col)) return f(st, end, col + 1);
    frr(i, st + 1, end) {
        if (ss[i][col] < ss[i - 1][col]) {
            removed.insert(col);
            return f(st, end, col + 1);
        }
    }

    for(int i = st; i < end;) {
        int d = 0;
        while (i+d < end && ss[i + d][col] == ss[i][col]) d++;
        if(d > 1)
            f(i,i+d,col+1);
        i = i+d;
    }
}
void Ma7moood() {
    in(n)
    in(m)
    ss = V<string>(n);
    cin(ss);

    int si = -1;
    while(removed.size() != si )
        si = removed.size(), f(0,n,0) ;
    cout << removed.size() << endl;
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