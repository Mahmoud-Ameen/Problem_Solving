/*
 * problem link: https://codeforces.com/contest/378/problem/B
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

#define in(i) int i;cin>>i;
#define inl(i) ll i;cin>>i;
#define ins(i) string i;cin>>i;

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;


void Ma7moood(){
    in(n);

    V<PII> a(n),b(n);
    fr(i,n){
        a[i].second = b[i].second = i;
        cin>>a[i].first >> b[i].first;
    }
    sort(all(a));
    sort(all(b));

    V<bool> sa(n),sb(n);

    for (int i = 0; i < n/2; ++i) {
        sa[i] = sb[i] = true;
    }

    int i = 0;
    int j = 0;
    int count = 0;
    while(count++ < n){
        if(a[i] < b[j]){
            sa[i] = true;
            i++;
        }else{
            sb[j] = true;
            j++;
        }
    }

    string saa,sbb;
    for (int k = 0; k < n; ++k) {
        if(sa[k])saa+='1';
        else saa+='0';

        if(sb[k])sbb+='1';
        else sbb+='0';
    }


    cout << saa << endl << sbb <<endl;
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}