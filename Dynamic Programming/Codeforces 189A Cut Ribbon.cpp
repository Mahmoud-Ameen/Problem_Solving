//
// Problem link: https://codeforces.com/problemset/problem/189/A
//

#include <bits/stdc++.h>
using namespace std;

vector<int> memo;
int solveRecursive(int target, int a, int b, int c){
    if(target == 0) return 0;

    if(memo[target] != -1) return memo[target];

    int c1=-1e8,c2=-1e8,c3=-1e8;

    if(target >= a) c1 = 1 + solveRecursive(target - a, a, b, c);
    if(target >= b) c2 = 1 + solveRecursive(target - b, a, b, c);
    if(target >= c) c3 = 1 + solveRecursive(target - c, a, b, c);

    return memo[target] = max({c1,c2,c3});
}

int main(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    memo = vector<int>(n+1,-1);
    cout << solveRecursive(n, a, b, c) << endl;
}