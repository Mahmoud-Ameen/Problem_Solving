//
// Created by MAHMOUD on 4/8/2024.
//

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
ll closest(const vector<ll>& arr1, const vector<ll>& arr2, long double x) {
    int i = 0, j = arr2.size() - 1;

    long double min_diff = LONG_LONG_MAX;
    ll result;
    while (i < arr1.size() && j >= 0) {
        ll current_sum = arr1[i] + arr2[j];
        long double diff = abs(current_sum - x);

        if (diff < min_diff) {
            min_diff = diff;
            result = current_sum;
        }

        if (current_sum < x)
            i++;
        else
            j--;
    }

    return result;
}
void Ma7moood(){
    ll n,m,k;
    cin >> n >> m >> k;

    VLL a(n),d(m),f(k);
    cin(a);
    cin(d);
    cin(f);

    // largest imbalance
    ll imbalance = 0;
    int ii = -1;
    for (int i = 1; i < n; ++i) {
        if(a[i] - a[i-1] > imbalance){
            ii = i-1;
            imbalance = a[i] - a[i-1];
        }
    }

    sort(all(f));
    sort(all(d));

    // Search for a model + function
    // that is closest to the middle of the two numbers causing the largest imbalance
    auto p = closest(d,f,a[ii] + imbalance/2.0);
    a.push_back(p);
    sort(all(a));

    // find imbalance after insertion
    ll nImbalance = 0;
    for (int i = 1; i < n+1; ++i) {
        if(a[i] - a[i-1] > nImbalance){
            nImbalance = a[i] - a[i-1];
        }
    }

    cout << min(nImbalance,imbalance) <<endl;
}



int main(){
    int t = 1;
    cin >> t;
    while(t--){
        Ma7moood();
    }
}