/*
 * Problem link: https://codeforces.com/contest/1900/problem/D
 * Rating: 2000
 * */

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i <<" "
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    // Get Sorted Divisors of every number from 1 to n
    const int N = 1e5;
    vector<vector<int>> divisors(N + 1);
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; j+=i)
            divisors[j].emplace_back(i);

    for (int i = 0; i <= N; ++i)
        sort(rall(divisors[i]));

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        cin(nums);
        sort(all(nums));

        ll ans = 0;
        vector<int> count(N+1);
        for (int i = 0; i < n; i++) {
            int b = nums[i];

            vector<int> temp(N+1);
            for (auto divisor: divisors[b]) {
                ll number = 1ll * count[divisor] - temp[divisor];
                ans += number * divisor * (n-1-i);

                for(auto dd: divisors[divisor])
                    temp[dd] += number;

                count[divisor]++;
            }
        }
        cout << ans <<endl;
    }
}