/*
 * Problem link: https://codeforces.com/contest/1945/problem/A
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
    ll introverts, extroverts ,universals ;
    cin >> introverts >> extroverts >> universals ;

    ll ans = introverts; // Place each introvert in a tent alone
    ans += extroverts / 3; // Place each 3 extroverts in a tent
    extroverts -= extroverts / 3 * 3;
    if(extroverts){
        if(universals >= 3 - extroverts){
            ans++;
            universals-= 3 - extroverts;
        }
        else return void(cout << "-1\n");
        // No universals enough to fill the tent with remaining extroverts
    }

    ans+= universals / 3; // Place every 3 universals in a tent
    universals-= universals / 3 * 3;
    if(universals) ans++;

    cout << ans <<endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){

        Ma7moood();
    }
}