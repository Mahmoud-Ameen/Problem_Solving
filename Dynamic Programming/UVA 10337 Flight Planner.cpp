/*
 * Problem link: https://vjudge.net/problem/UVA-10337
 * */

#include <bits/stdc++.h>
using namespace std;

const int oo = 1e8;

vector<vector<int>> wind;
vector<vector<int>> memo;
int x;

int solve(int steps, int alt){
    if(steps * 100 == x) {
        if (alt == 0)
            return 0;
        else return oo;
    }

    if(memo[steps][alt] != -1)
         return memo[steps][alt];

    int climb = oo, sink = oo, hold = oo;

    // climb
    if(alt < 9)
        climb = 60 + wind[alt][steps] + solve(steps + 1, alt + 1);
    // sink
    if(alt > 0)
        sink = 20 + wind[alt][steps] + solve(steps + 1, alt - 1);

    // hold altitude
    hold = 30 + wind[alt][steps] + solve(steps + 1, alt);

    return memo[steps][alt] = min(climb, min(sink, hold));
}

int main(){
    int t;
    cin >>t;
    while(t--){
        cin >> x;
        wind.clear();
        memo.clear();
        wind.resize(10,vector<int>(x/100+1));
        memo.resize(x/100+1,vector<int>(10,-1));

        for (int i = 9; i >= 0; --i) {
            for (int j = 0; j < x/100; ++j) {
                cin>> wind[i][j];
                wind[i][j] *= -1;
            }
        }
        cout << solve(0,0) << endl << endl;

    }
}