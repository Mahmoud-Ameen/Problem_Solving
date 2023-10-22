//
// Problem link: https://vjudge.net/problem/UVA-825
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int W,N;
vector<vector<bool>> safe;
vector<vector<int>> memo;
int solve(int posX, int posY){
    if (posX == N && posY == W)
        return 1;
    if(posX > N || posY > W) return 0;

    if(memo[posY][posX] != -1) return memo[posY][posX];

    int ways = 0;
    if(posX  < N && safe[posY][posX+1])
        ways += solve(posX+1,posY);
    if(posY < W && safe[posY+1][posX])
        ways += solve(posX,posY+1);

    return memo[posY][posX] = ways;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> W >> N;
        safe.clear();
        memo.clear();
        safe.resize(W+1,vector<bool>(N+1,true));
        memo.resize(W+1,vector<int>(N+1,-1));

        cin.ignore();
        for (int i = 0; i < W; ++i) {
            int x,y;
            string line;
            getline(cin, line);
            istringstream iss(line);
            iss >> x;
            while (iss >> y) {
                safe[x][y] = false;
            }
        }
        cout << solve(1,1) << endl;
        if(t!=0) cout << endl;
    }
}