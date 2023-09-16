/*
 * Problem link: https://codeforces.com/problemset/problem/830/A
 * Rate: 1800
 *
 * Note:
 * If the persons and keys were approached from left to right,
 * we will somehow find that on connecting each person to a key,
 * the optimal solution will never consist of crossing lines.
 * That is: the best key for the person in position i will always be after the best keys for
 * persons in positions < i.
 *
 * It is hard to prove but try drawing different cases on a piece of paper and check.
 * */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll oo = 1e15;
int n,k,p;
vector<int> people;
vector<int> keys;

vector<vector<ll>> dp (1001,vector<ll>(2001,-1));
ll solve(int personIndex,int keyIndex){
    if(personIndex == n) return 0;
    if(keyIndex == k) return oo;

    if(dp[personIndex][keyIndex] != -1) return dp[personIndex][keyIndex];

    ll distance = abs(p - keys[keyIndex]) + abs(keys[keyIndex] - people[personIndex]);

    ll takeKey = max(distance, solve(personIndex + 1, keyIndex + 1));
    ll dontTakeKey = solve(personIndex,keyIndex+1);

    return dp[personIndex][keyIndex] = min(takeKey, dontTakeKey);
}

int main(){
    cin >> n >> k >> p;
    people.resize(n);
    keys.resize(k);

    for (int i = 0; i < n; ++i)
        cin >> people[i];
    for (int i = 0; i < k; ++i)
        cin >> keys[i];

    std::sort(people.begin(), people.end());
    std::sort(keys.begin(), keys.end());

    cout << solve(0,0);
}