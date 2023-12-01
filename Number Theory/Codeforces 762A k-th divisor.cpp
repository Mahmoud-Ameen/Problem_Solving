/*
 * Problem link: https://codeforces.com/problemset/problem/762/A
 * */

#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define ll long long
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

using namespace std;

/*
 * get all divisors of a number and store them in %result
 * O(sqrt(n))
 * */
void getDivisors(long long n, std::vector<long long>& result) {
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

int main(){
    ll n ,k;
    cin >> n>>k;

    vector<ll> res;
    getDivisors(n,res);

    if(k > res.size())
        cout << "-1\n";
    else cout << (res[k-1]) << endl;

}