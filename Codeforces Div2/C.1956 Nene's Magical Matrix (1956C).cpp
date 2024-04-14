/*
 * Problem link: https://codeforces.com/contest/1956/problem/C
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
#define cyes cout << "YES\n";
#define cno cout << "NO\n";

// Matrix graph traversals
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

void Ma7moood() {
    in(n)

    V<VI> operations;
    V<VI> grid(n, VI(n));

    for (int i = n; i > 0; --i) {
        // Perform type one operation with permutation 1,2,3,...,n
        // on row i
        operations.push_back({ 1, i });
        for (int j = 1; j <=n ; ++j)
            operations.back().push_back(j);

        // Perform type two operation with permutation 1,2,3,...,n
        // on col i
        operations.push_back({2, i});
        for (int j = 1; j <=n ; ++j) {
            operations.back().push_back(j);
        }
    }


    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum+= i * ( i * 2 - 1 );
    }

    cout << sum << " " << operations.size() << endl;

    for(auto&& operation: operations) {
        cout (operation);
        cout << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
    cin >> t;
    while(t--){
        Ma7moood();
    }
}