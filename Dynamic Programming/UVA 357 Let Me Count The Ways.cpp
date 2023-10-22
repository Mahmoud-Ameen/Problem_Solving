#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const double EPS = 1e-9;
const int MX_COIN = 30005;
const int COINS_NUMBER = 5;

vector<int> coins {1,5,10,25,50};
vector<vector<ll>> memo (MX_COIN,vector<ll>(COINS_NUMBER+1,-1));

ll solve(int amount,int idx){
    if(amount == 0) return 1;
    if(idx == COINS_NUMBER || amount < 0) return 0;

    if(memo[amount][idx] != -1) return memo[amount][idx];

    return memo[amount][idx] = solve(amount-coins[idx],idx) + solve(amount,idx+1);
}

int main (){
    int cents;

    solve(10000,0);
    solve(20000,0);
    solve(30000,0);

    while(cin >> cents){
        ll ans = solve(cents,0);
        if(ans == 1)
            cout<< "There is only 1 way to produce "<<cents <<" cents change.\n";
        else
            cout << "There are "<< ans << " ways to produce "<<cents<<" cents change.\n";
    }
}
