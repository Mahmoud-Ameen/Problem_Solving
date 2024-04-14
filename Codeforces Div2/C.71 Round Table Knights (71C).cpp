/*
 * Problem link: https://codeforces.com/contest/71/problem/C
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

void getDivisors(int n, std::vector<int>& result) {
    long long i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            result.emplace_back(i);
            result.emplace_back(n / i);
        }
    }
    if(i * i == n) result.emplace_back(i);
    // Note that number of divisors is usually negligible compared to n
    std::sort(result.begin(),result.end());
}

void Ma7moood() {

    in(n)
    VI a(n);
    cin(a);

    VI divs;
    getDivisors(n,divs);
    for(int& div: divs){
        if(div < 3) continue;
        for (int st = 0; st < n; ++st) {
            int count = div;
            while(count){
                if(!a[(st+(n/div)*count )% n]) break;
                count--;
            }
            if(!count) {
                cyes;
                return;
            }
        }
    }

    cno;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}