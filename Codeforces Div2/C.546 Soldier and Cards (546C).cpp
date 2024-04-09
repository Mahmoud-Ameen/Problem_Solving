/*
 * problem link: https://codeforces.com/contest/546/problem/C
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
#define frll(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;


void Ma7moood(){
    ll n,a,b;
    cin >> n >> a ;
    queue<int> qa,qb;
    for (int i = 0; i < a; ++i) {
        int x;
        cin >> x;
        qa.push(x);
    }
    cin >> b;
    for (int i = 0; i < b; ++i) {
        int x;
        cin >> x;
        qb.push(x);
    }

    int fights = 0;
    while(!qa.empty() && !qb.empty()){
        fights++;
        int aa = qa.front(); qa.pop();
        int bb = qb.front(); qb.pop();

        if(fights > 10000)
            return void(cout << "-1\n");

        if(aa > bb){
            qa.push(bb);
            qa.push(aa);
        }else{
            qb.push(aa);
            qb.push(bb);
        }
    }

    cout << fights << " ";
    if(qa.empty()) cout << 2;
    else cout << 1;
    cout << endl;
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}