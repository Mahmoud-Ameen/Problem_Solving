/*
 * Problem link: https://codeforces.com/problemset/problem/1555/C
 * Rating: 1300
 * Category: Prefix Sum
 * */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1e12;
const ll noo = -1e12;

int main(){
    int t;
    cin >> t;
    vector<vector<int>> grid (2,vector<int>(1e5+5));

    while(t--){
        int m;
        cin >> m;
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> grid[i][j];
            }
        }

        // Prefix Sum
        for (int i = 1; i <= m; ++i) {
            grid[0][i] += grid[0][i-1];
            grid[1][i] += grid[1][i-1];
        }

        int answer = 1e9;
        for (int i = 0; i <= m; ++i) {
            answer = min(answer, max(grid[0][m] - grid[0][i], grid[1][i-1]));
        }

        cout << answer << endl;
    }
}