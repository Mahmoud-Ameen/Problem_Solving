//
// Problem link: https://codeforces.com/contest/225/problem/C
//

#include <bits/stdc++.h>
using namespace std;

const int oo = 1e8;
const int MAX_N = 1000 + 5;

int rows,cols;
int x,y;

vector<int> white (MAX_N); // Number of white cells in each column
vector<int> black (MAX_N); // Number of black cells in each column

// dp[index][width of previous columns group][color of group]
vector<vector<vector<int>>> dp (MAX_N,vector<vector<int>>(MAX_N,vector<int>(3,-1)));

int solve(int index,int width,int prev){
    if(index == cols) {
        if(width < x) return oo;
        return 0;
    }

    if(dp[index][width][prev] != -1)
            return dp[index][width][prev];

    // Group's width less than minimum
    // Must paint this column as well with same color
    if(width < x && prev == 0)
        return dp[index][width][prev] = white[index] + solve(index + 1, width+1, 0);

    // Group's width less than minimum
    // Must paint this column as well with same color
    if(width < x && prev == 1)
        return dp[index][width][prev] = black[index] + solve(index + 1, width+1, 1);

    int choiceBlack = oo;
    int choiceWhite = oo;
    // Group can be extended,
    // Either extend it by coloring this column with same color
    // or start a new one of the other color with width.
    if(width < y){
        if(prev == 0 ) {
            choiceBlack = white[index] + solve(index + 1, width + 1, 0);
            choiceWhite = black[index] + solve(index+1,1,1);
        }
        else {
            choiceWhite = black[index] + solve(index + 1, width + 1, 1);
            choiceBlack = white[index] + solve(index + 1, 1, 0);
        }
    }

    // Group can't be extended further,
    // Must color this column with the opposite color
    if(width == y){
        if(prev == 0)
            choiceWhite = black[index] + solve(index+1,1,1);
        if(prev == 1)
            choiceBlack = white[index] + solve(index+1,1,0);
    }

    return dp[index][width][prev] = min(choiceBlack,choiceWhite);
}

int main(){
    cin >> rows >> cols >> x >> y;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char ch;
            cin >> ch;
            if(ch == '.')
                white[j]++;
            else black[j]++;
        }
    }

    cout << solve(0,0,2) << endl;

}