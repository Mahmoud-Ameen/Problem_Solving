//
// Problem link: https://codeforces.com/contest/366/problem/C
//

/* First of all, let's introduce a notation: (x,y) represents a fruit of taste x and calories y.
 *
 * If fruits (a,x), (b,y), (c,z) follows the principle then:
 *   (a+b+c)/(x+y+z) = k
 * => a+b+c = k(x+y+z)
 * => a+b+c - k(x+y+z) = 0
 * => a+b+c - kx - ky - kz = 0
 * => (a-kx) + (b-ky) + (c-kz) = 0
 * So we notice that if we stored [taste-k*calories] (*lets call it diff*) for each fruit,
 * The problem converts to a regular Knapsack problem where we try to find subsets of fruits
 * where sum of their diff equals zero and the sum of their taste is maximum.
 * */

#include <bits/stdc++.h>
using namespace std;

const int NEGATIVE_INF = -1e9;
const int MAX_N = 100+5;

int n,k;
vector<int> tastes(MAX_N);
vector<int> calories(MAX_N);
vector<int> diff(MAX_N);

// memo[index][isFirst][need]
vector<vector<unordered_map<int,int>>> memo (MAX_N,vector<unordered_map<int,int>>(2));

int solve(int i, int need, bool isFirst){
    if(i == n){
        if(need == 0 && !isFirst) return 0;
        else return NEGATIVE_INF;
    }

    if(memo[i][isFirst].find(need) != memo[i][isFirst].end())
        return memo[i][isFirst][need];

    int take = tastes[i] + solve(i+1,need + diff[i],false);

    int leave = solve(i+1,need,isFirst);

    return memo[i][isFirst][need] = max(take,leave);
}

int main(){
    cin >> n>>k;
    for (int i = 0; i < n; ++i) {
        cin >> tastes[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> calories[i];
        diff[i] = tastes[i] - k * calories[i];
    }

    int solution = solve(0,0,true);
    cout << (solution >= 0 ? solution: -1);
}