/*
 * problem link: https://vjudge.net/problem/UVA-439
 * */

#include <bits/stdc++.h>
using namespace std;

void findMinimumKnightMoves(int row, int col, vector<vector<int>>& minMoves, int moves){
    // recursive call chain ends when there is no longer a square that wasn't
    //                                                 visited in least moves
    if (row <= 7 && row >= 0 && col <= 7 && col >= 0 && moves < minMoves[row][col]){
        minMoves[row][col] = moves;

        // each recursive call represent a square a knight can move to
        findMinimumKnightMoves(row + 2, col + 1, minMoves, moves + 1);
        findMinimumKnightMoves(row + 2, col - 1, minMoves, moves + 1);
        findMinimumKnightMoves(row - 2, col + 1, minMoves, moves + 1);
        findMinimumKnightMoves(row - 2, col - 1, minMoves, moves + 1);
        findMinimumKnightMoves(row + 1, col + 2, minMoves, moves + 1);
        findMinimumKnightMoves(row + 1, col - 2, minMoves, moves + 1);
        findMinimumKnightMoves(row - 1, col + 2, minMoves, moves + 1);
        findMinimumKnightMoves(row - 1, col - 2, minMoves, moves + 1);
    }
}


int main()
{
    string start;



    while (cin >> start)
    {
        vector<vector<int>> minMoves;
        for (int i = 0; i < 8; i++) {
            minMoves.emplace_back();
            for (int j = 0; j < 8; j++)
                minMoves[i].push_back(INT_MAX);
        }

        string end;
        cin >> end;

        int startRow = start[0] - 'a';
        int startCol = start[1] - '1';


        findMinimumKnightMoves(startRow, startCol, minMoves, 0);

        int endRow = end[0] - 'a';
        int endCol = end[1] - '1';

        cout << "To get from " << start << " to " << end << " takes " << minMoves[endRow][endCol] << " knight moves." << endl;
    }
}