/*
 * problem link: https://codeforces.com/contest/518/problem/B
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
#define PII pair<int,int>
#define PLL pair<ll,ll>

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;


void Ma7moood(){
    string a,b;
    cin >> a >> b;

    map<char,int> frequencyInS;
    for(auto&& ch: a)
        frequencyInS[ch]++;

    map<char,int> frequencyInT;
    for (auto&& ch: b)
        frequencyInT[ch]++;


    int yay = 0;
    int whoops = 0;

    for(auto&& p: frequencyInS){
        int matches = min(p.second, frequencyInT[p.first]);
        yay += matches;
        p.second-=matches;
        frequencyInT[p.first]-=matches;
    }

    for(auto&& p: frequencyInS){
        if (p.second > 0) {
            char alt;
            if(p.first <= 'Z') alt = p.first + 32;
            else alt = p.first - 32;
            whoops += min(p.second, frequencyInT[alt]);
            frequencyInT[alt] -= min(p.second, frequencyInT[alt]);
        }
    }

    cout << yay <<" " << whoops << endl;
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}