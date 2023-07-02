
/*
 * problem link: https://vjudge.net/problem/UVA-167
 * */

#include <bits/stdc++.h>

using namespace std;

int values[8][8];
vector<vector<int>> attacked;
int mx = INT_MIN;

void mutateBoard(int row,int col,bool queenAdded){
    vector<vector<int>> ref = attacked;


    for (int i = 0; i < 8; ++i) {
        if(queenAdded){
            attacked[row][i] = ref[row][i] + 1;
            attacked[i][col] = ref[i][col] + 1;
        }
        else{
            attacked[row][i] = ref[row][i] - 1;
            attacked[i][col] = ref[i][col] - 1;
        }
    }
    // formula for main diagonal: row+i,col+i
    for (int i = -7; i < 8; ++i) {
        bool isValidRow = row + i >=0 && row + i < 8;
        bool isValidCol = col + i >=0 && col + i < 8;

        if(isValidRow && isValidCol) {
            if(queenAdded)
                attacked[row+i][col+i] = ref[row+i][col+i] + 1;
            else
                attacked[row+i][col+i] = ref[row+i][col+i] - 1;
        }
    }
    // formula for sec diagonal: row+i,col-i
    for (int i = -7; i < 8; ++i) {
        bool isValidRow = row + i >=0 && row + i < 8;
        bool isValidCol = col - i >=0 && col - i < 8;

        if(isValidRow && isValidCol){
            if(queenAdded)
                attacked[row+i][col-i] = ref[row+i][col-i] + 1;
            else
                attacked[row+i][col-i] = ref[row+i][col-i] - 1;
        }
    }

}

// queen number from 0 to 7
void backtrack(int queenNumber,int sum){

    if(queenNumber == 8) {
        mx = max(mx,sum);
        return;
    }

    for (int col = 0; col < 8; ++col) {
        if(!attacked[queenNumber][col]){
            // decided to put a queen on this square
            mutateBoard(queenNumber,col,true);
            backtrack(queenNumber+1,sum + values[queenNumber][col]);

            // decided not to put a queen on this square
            mutateBoard(queenNumber,col,false);
        }
    }

}

void solve(){ backtrack(0,0); }

int main(){
    int k;
    cin >> k;

    for (int test = 0; test < k; ++test) {
        attacked.clear();
        mx = INT_MIN;
        for (int i = 0; i < 8; ++i) {
            attacked.emplace_back();
            for (int j = 0; j < 8; ++j) {
                cin >> values[i][j];
                attacked[i].push_back(0);
            }
        }

        solve();
        cout << right << setw(5) << mx << '\n';
    }
}