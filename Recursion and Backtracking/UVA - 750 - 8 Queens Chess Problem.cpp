/*
 * problem link : https://vjudge.net/problem/UVA-750
 * solution by Mahmoud Ashraf
 * */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> attacked;
unordered_set<int> remainingQueens;
vector<map<int,int>> solutions;


void mutateBoard(int row,int col,bool queenAdded){
    vector<vector<int>> ref = attacked;

    if(queenAdded)
        remainingQueens.erase(col);
    else
        remainingQueens.insert(col);

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
// queen number represents column
void backtrack(map<int,int>& solution){
    // terminal condition: no remaining queen to be added
    if(remainingQueens.empty()){
        solutions.push_back(solution);
        return;
    }

    // get any queen number that wasn't added before
    // (column that has no queens in it)
    int queenNumber;
    for (int i = 0; i < 8; ++i) {
        if(remainingQueens.find(i) != remainingQueens.end()) {
            queenNumber = i;
            break;
        }
    }

    for (int row = 0; row < 8; ++row) {
        if(!attacked[row][queenNumber]){
            // start a branch where there is a queen on this square
            mutateBoard(row,queenNumber,true);
            solution[queenNumber] = row;
            backtrack(solution);

            // revert changes to look for another square to put the queen in
            mutateBoard(row,queenNumber,false);
            solution.erase(queenNumber);
        }
    }

}

void solve(int firstRow,int firstCol){
    map<int,int> temp;
    temp[firstCol -1 ] = firstRow - 1;
    mutateBoard(firstRow - 1 ,firstCol - 1 ,true);

    backtrack(temp);
}

void output(){
    cout << "SOLN       COLUMN\n"
            " #      1 2 3 4 5 6 7 8\n\n";

    for (int i = 0; i < solutions.size(); ++i) {
        if((i+1)/10 == 0)
            cout<< " " << i+1 <<"     ";
        else
            cout<< i+1 <<"     ";

        auto solution = solutions[i];
        for(const auto& colRow : solution){
            cout << " " << colRow.second + 1;
        }
        cout << '\n';
    }
}

int main(){

    int k;
    cin >> k;

    for (int test = 0; test < k; ++test) {
        attacked.clear();
        remainingQueens.clear();
        solutions.clear();

        remainingQueens.insert(0);
        remainingQueens.insert(1);
        remainingQueens.insert(2);
        remainingQueens.insert(3);
        remainingQueens.insert(4);
        remainingQueens.insert(5);
        remainingQueens.insert(6);
        remainingQueens.insert(7);

        for (int i = 0; i < 8; ++i) {
            attacked.emplace_back();
            for (int j = 0; j < 8; ++j) {
                attacked[i].push_back(false);
            }
        }
        int firstRow,firstCol;
        cin >> firstRow >> firstCol;


        solve(firstRow,firstCol);

        output();
        cout << (test != k-1 ? "\n" : "");
    }
}

