/*
 * Problem link: https://codeforces.com/contest/711/problem/C
 * */

#include <bits/stdc++.h>
using namespace std;


const int oo = 1e8; // INFINITY
const int MAX_N = 100000 + 5;
int n;
string s;
vector<vector<vector<int>>> dp(MAX_N, vector<vector<int>>(3, vector<int>(2, -1)));
vector<vector<vector<bool>>> path(MAX_N, vector<vector<bool>>(3, vector<bool>(2)));

int solve(int i, int sumMod3, bool isFirst){
    if(i == n) {
        if(sumMod3 == 0 && !isFirst) return 0;
        return oo;
    }

    if(dp[i][sumMod3][isFirst] != -1) return dp[i][sumMod3][isFirst];

    // Delete This Digit:
    int choiceDelete = 1 + solve(i + 1, sumMod3, isFirst);

    // Keep This Digit:
    int choiceTake = oo;
    if(!(isFirst && (s[i] == '0') ))
        choiceTake = solve(i + 1, abs((sumMod3 + (s[i] - '0') % 3) % 3), false);


    if(choiceDelete < choiceTake) {
        dp[i][sumMod3][isFirst] = choiceDelete;
        path[i][sumMod3][isFirst] = false;
    }
    else{
        dp[i][sumMod3][isFirst] = choiceTake;
        path[i][sumMod3][isFirst] = true;
    }

    return dp[i][sumMod3][isFirst];
}

// Follow path chosen by the function used to calculate the min path
// Start fom the same start and follow the recorded path
void extractSolution(int i, int sumMod3, bool isFirst){
    if(i == n) return;

    if(path[i][sumMod3][isFirst])
    {
        cout << s[i];
        extractSolution(i + 1, abs((sumMod3 + (s[i] - '0') % 3) % 3), false);
    }
    else
        extractSolution(i + 1, sumMod3, isFirst);

}

int main(){
    cin >> s;
    n = static_cast<int>(s.size());

    int minDeletions = solve(0, 0, true);

    if(minDeletions < oo) {
        extractSolution(0,0,true);
        cout << endl;
    }
    else {
        for (const char& c:s) {
            // If no answer was found but there exist a zero, it would be the answer
            if(c == '0'){
                cout << 0<<endl;
                return 0;
            }
        }
        cout << -1 << '\n';
    }
}