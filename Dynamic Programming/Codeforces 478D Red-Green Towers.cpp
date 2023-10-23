/*
 * Problem link: https://codeforces.com/contest/478/problem/D
 * Rate: 2000
 * */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

int main(){
    int green, red;
    cin >> green >> red;

    // Get Max number of levels can be made
    int h = sqrt((green + red) * 2);
    while(h * (h+1) > (green + red) * 2)
        h--;

    // Blocks needed to fill h levels
    int blocksNeeded = h * (h + 1) / 2;
    // Extra blocks we have
    int extra = green + red - blocksNeeded ;
    // Blocks color with the least number
    int least = min(green, red);


    vector<ll> currentDp (vector<ll>(least + 1));
    vector<ll> prevDp (vector<ll>(least + 1));

    // Initialize base cases
    prevDp[0] = 1;
    currentDp[0] = 1;

    for (int level = 1; level <= h; ++level) {
        for (int blocks_i = 0; blocks_i <= least; ++blocks_i) {
            currentDp[blocks_i] = prevDp[blocks_i];

            if(blocks_i >= level)
                currentDp[blocks_i] += prevDp[blocks_i - level];

            currentDp[blocks_i] %= MOD;
        }
        swap(prevDp, currentDp);
    }

    ll ans = 0;
    for (int i = 0; i <= extra && i <= least; ++i) {
        ans += prevDp[least - i];
        ans %= MOD;
    }

    cout << ans << endl;
}
