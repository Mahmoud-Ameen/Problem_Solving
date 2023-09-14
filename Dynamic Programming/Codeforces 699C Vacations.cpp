/*
 * Problem link: https://codeforces.com/contest/699/problem/C.
 * Rate: 1400
 * */

#include <bits/stdc++.h>
using namespace std;

const int oo = 1e8;
const int MAX_N = 102;

int n;
vector<int> days(MAX_N);

//dp[index][prev]
vector<vector<int>> dp(MAX_N, vector<int>(4,-1));

/*
    Activities
    0, rest;
    1, contest / rest;
    2, sport /rest;
    3, sport/contest/rest.
*/

/*
    prev 0 -> rested the day before
    prev 1 -> did sport the day before
    prev 2 -> wrote a contest the day before
*/

int solve(int day, int prev){
    if(day == n) return 0;

    if(dp[day][prev] != -1) return dp[day][prev];

    // If no activity can be done in this day, rest
    int rest = 1 + solve(day + 1, 0);
    if(days[day] == 0)
        return dp[day][prev] = rest;

    // If the gym is open and didn't do sports the day before,
    // You can do sports.
    int sports = oo;
    if((days[day] == 1 || days[day] == 3) && prev != 1)
        sports = solve(day + 1, 1);


    // If the contest is carried out and didn't write a contest the day before,
    // You can write a contest.
    int contest  = oo;
    if((days[day] == 2 || days[day] == 3) && prev != 2)
        contest = solve(day + 1, 2);

    return dp[day][prev] = min({contest, sports, rest});
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> days[i];

    cout << solve(0,0)<<endl;
}