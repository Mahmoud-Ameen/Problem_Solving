//
// Created by MAHMOUD on 10/22/2023.
//
#include <bits/stdc++.h>
using namespace std;

int sz1,sz2;
vector<string> a,b;
vector<vector<int>> memo;
vector<vector<int>> path;

int longestCommonSubsequence(int i, int j){
    if(i == sz1 || j == sz2)
        return 0;

    if(memo[i][j] != -1) return memo[i][j];

    if(a[i] == b[j]) {
        path[i][j] = 0;
        return memo[i][j] = 1 + longestCommonSubsequence(i + 1, j + 1);
    }

    int choice1 = longestCommonSubsequence(i + 1, j),
        choice2 = longestCommonSubsequence(i, j + 1);
    if(choice1 >= choice2)
        path[i][j] = 1;
    else path[i][j] = 2;

    return memo[i][j] = max(choice1,choice2) ;
}

vector<int> output;
void generateOutput(int i,int j){
    if(i == sz1 || j == sz2) return;

    if(path[i][j] == 0) {
        output.push_back(i);
        return generateOutput(i+1,j+1);
    }
    if(path[i][j] == 1)
        return generateOutput(i+1,j);

    if(path[i][j] == 2)
        return generateOutput(i,j+1);
}

int main(){

    string word;
    while(cin >> word) {
        // Clear all global data structures
        a.clear();
        b.clear();
        output.clear();
        memo.clear();
        path.clear();

        // Take input
        a.push_back(word);
        while (true) {
            cin >> word;

            if (word == "#") break;

            a.push_back(word);
        }

        while (true) {
            cin >> word;

            if (word == "#") break;

            b.push_back(word);
        }

        // Solving
        sz1 = a.size();
        sz2 = b.size();

        memo.resize(sz1 + 1, vector<int>(sz2 + 1, -1));
        path.resize(sz1 + 1, vector<int>(sz2 + 1, -1));

        longestCommonSubsequence(0, 0);
        generateOutput(0, 0);

        // Output
        cout << a[output[0]];
        for (int i = 1; i < output.size(); ++i) {
            cout << " " << a[output[i]];
        }
        cout << endl;
    }
}