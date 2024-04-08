/*
 * problem link: https://codeforces.com/contest/515/problem/C
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
    ll n;
    string s;
    cin >> n >> s;

    map<char,vector<int>> rep;
    rep['4'] = {3,2,2};
    rep['6'] = {3,5};
    rep['8'] = {2,2,2,7};
    rep['9'] = {2,3,3,7};

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '0' || s[i] == '1') continue;
        if(rep.find(s[i]) == rep.end()) ans.push_back(s[i]-'0');
        else
            for (auto&& k:rep[s[i]]) ans.push_back(k);
    }
    sort(rall(ans));
    for (auto&& k: ans) {
        cout <<k;
    }
    cout <<endl;
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}