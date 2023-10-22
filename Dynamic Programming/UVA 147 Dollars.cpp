#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const double EPS = 1e-9;
const int MX_COIN = 30005;
const int COINS_NUMBER = 11;

vector<int> coins {10000,5000,2000,1000,500,200,100,50,20,10,5};
vector<vector<ll>> memo;
ll solve(int amount,int i){
    if(amount == 0) return 1;
    if (i == COINS_NUMBER || amount < 0) return 0;

    if(memo[amount][i] != -1) return memo[amount][i];

    ll take = solve(amount-coins[i], i);
    ll leave = solve(amount,i+1);

    return memo[amount][i] = take + leave;
}

int main(){
    double am;
    reverse(coins.begin(),coins.end());
    memo.resize(MX_COIN,vector<ll>(COINS_NUMBER, -1));
    while(true){
        cin >> am;
        if(am == 0) break;

        cout << fixed << right << setw(6) << setprecision(2) << am
            << setw(17) << solve(int((am+EPS) * 100),0) << endl;
    }
}
