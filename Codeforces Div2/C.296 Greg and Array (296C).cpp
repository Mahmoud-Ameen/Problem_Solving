/*
 * problem link: https://codeforces.com/contest/296/problem/C
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
    int n,m,k;
    cin >> n >> m >> k;

    VLL nums(n);
    cin(nums);

    VLL increment(n + 1);
    V<VLL> operations(m, VLL(3));
    for (int i = 0; i < m; ++i) {
        cin >> operations[i][0] >> operations[i][1] >> operations[i][2];
        operations[i][0]--;
        operations[i][1];
    }
    VLL operationsRepetition(m + 1);
    for (int i = 0; i < k; ++i) {
        int x,y;
        cin >> x >> y;

        operationsRepetition[x - 1]++;
        operationsRepetition[y]--;
    }

    for (int i = 1; i < m; ++i)
        operationsRepetition[i] += operationsRepetition[i - 1];


    for (int i = 0; i < m; ++i) {
        increment[operations[i][0]] += operationsRepetition[i] * operations[i][2];
        increment[operations[i][1]] -= operationsRepetition[i] * operations[i][2];
    }

    for (int i = 1; i < n; ++i)
        increment[i] += increment[i - 1];

    for (int i = 0; i < n; ++i) 
        cout << nums[i] + increment[i] << " ";

    cout << endl;

}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}