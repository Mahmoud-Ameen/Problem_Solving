/*
 * Problem link: https://codeforces.com/problemset/problem/735/D
 * Rating: 1600
 * */

#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define ll long long
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i <<" "
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

using namespace std;



bool isPrime(int n) {
    if(n == 2) return true;
    if(!(n & 1)) return false;

    for (int i = 3; i * i <= n; i+=2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int n = 2e8;
    cin >> n;

    bool p = isPrime(n);

    int ans;
    if(p || n == 1) ans =1;
    else{
        if(n&1) {
            if(n > 3 && isPrime(n-2)) ans = 2;
            else ans = 3;
        }
        else ans = 2;
    }
    cout << ans <<endl;
}