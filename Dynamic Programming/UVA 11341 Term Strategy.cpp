/*
 * Problem link: https://vjudge.net/problem/UVA-11341
 * */


#include <bits/stdc++.h>
using namespace std;

const int N_INF = -1e7;

vector<vector<int>> grades;
vector<vector<int>> memo;
int n,m;
int solve(int course,int hours){
    if(hours < 0) return N_INF;
    if(course == n) return 0;

    if(memo[course][hours] != -1) return memo[course][hours];

    int sol = N_INF;
    for (int i = 1; i <= m; ++i) {
        if(grades[course][i-1] >= 5)
            sol = max(sol,
                      grades[course][i-1] + solve(course+1, hours - i));
    }
    return memo[course][hours] = sol;
}

int main(){
    int t;
    cin >>t ;
    while(t--){
        cin >> n >> m;
        grades.clear();
        memo.clear();
        grades.resize(n,vector<int>(m));
        memo.resize(n,vector<int>(m+1,-1));
        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < m; ++j) {
                cin>>grades[i][j];
            }
        }

        int totalMarks = solve(0,m);
        if(totalMarks > 0)
            cout <<"Maximal possible average mark - " <<setprecision(2)<<fixed<< (double)(1e-9+totalMarks)/n << "." << endl;
        else cout <<"Peter, you shouldn't have played billiard that much."<<endl;
    }
}
