/*
 * problem link : https://vjudge.net/problem/UVA-10946
 * */

#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> visited;

int rows,cols;
map<int,vector<char>> solutions;

void findLargestGroup(char ch, int row, int col, vector<pair<int,int>>& st, int& solution){

    if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col]) {
        // Base case: out of bounds or already visited cell
        solution = max(solution, static_cast<int>(st.size()));
        return;
    }

    if (grid[row][col] != ch) {
        // Base case: character mismatch
        solution = max(solution, static_cast<int>(st.size()));
        return;
    }

    st.emplace_back(row,col);
    visited[row][col] = true;

    int nextRow = row + 1;
    int prevRow = row - 1;
    int nextCol = col + 1;
    int prevCol = col - 1;

    findLargestGroup(ch, nextRow, col, st, solution); // down
    findLargestGroup(ch, prevRow, col, st, solution); // up
    findLargestGroup(ch, row, nextCol, st, solution); // right
    findLargestGroup(ch, row, prevCol, st, solution); // left


}

// entry point for the solution
void solve(){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(!visited[i][j]) {
                int size = 0 ;
                vector<pair<int,int>> useless;
                findLargestGroup(grid[i][j], i, j, useless, size);
                solutions[size * -1].push_back(grid[i][j]);
            }
        }
    }

}

int main(){

    int problemNumber = 1;
    while(true){
        grid.clear();
        solutions.clear();
        visited.clear();

        cin >> rows >> cols;
        if(rows == 0 && cols == 0) break;

        // Read grid input and set visited[][]
        for (int i = 0; i < rows; ++i) {
            grid.emplace_back();
            visited.emplace_back();
            for (int j = 0; j < cols; ++j) {
                char ch;
                cin >> ch;
                grid[i].push_back(ch);
                visited[i].push_back(ch == '.');
            }
        }

        solve();

        // output
        cout <<"Problem "<<problemNumber <<":\n";
        problemNumber++;
        for (pair<int,vector<char>> sol:solutions) {
            sort(sol.second.begin(),sol.second.end());
            for (char ch: sol.second) {
                cout << ch << " " << sol.first * -1<<endl;
            }
        }

    }

}