/*
 * Problem link: https://codeforces.com/contest/1895/problem/C
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
    VLL a(n);
    V<string> s(n);
    cin(a);

    V<map<ll,ll>> count(6);
    fr(i,n){
        s[i] = to_string(a[i]);
        int sum = 0;
        for (char& ch: s[i])
            sum+=ch-'0';
        count[s[i].size()][sum]++;
    }

    ll ans = 0;
    fr(i,n) {
        ll addedSize = 2;
        if(s[i].size() & 1) addedSize = 1;

        for(; addedSize <= s[i].size(); addedSize+=2){
            ll newSize = addedSize + s[i].size();

            ll prefixSum = 0, totalSum = 0, suffixSum = 0;
            for (int j = 0; j < s[i].size(); j++) {
                if (j < newSize / 2) {
                    prefixSum += s[i][j] - '0';
                    suffixSum += s[i][s[i].size() - 1 - j] - '0';
                }
                totalSum += s[i][j] - '0';
            }

            ll s1 = prefixSum - (totalSum - prefixSum); // (i
            ll s2 = suffixSum - (totalSum - suffixSum);
            ans += count[addedSize][s1] ;
            if(addedSize != s[i].size())
                ans += count[addedSize][s2];
        }
    }
    cout << ans <<endl;
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