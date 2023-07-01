/*
 * problem link: https://vjudge.net/problem/UVA-100
 * */

#include <bits/stdc++.h>

using namespace std;

long long mx = INT_MIN;

void backtrack(long long num,long long cycleLength){
    bool isEven = num % 2 == 0;
    if(num == 1){
        mx = max(mx,cycleLength + 1);
        return;
    }

    if(isEven)
        backtrack(num / 2, cycleLength + 1);
    else
        backtrack(num*3+1, cycleLength + 1);

}

void solve(int start,int end){
    for (int i = start; i <= end; ++i) {
        backtrack(i,0);
    }
    for (int i = end; i <= start; ++i) {
        backtrack(i,0);
    }
}

int main(){


    int start,end;
    while(cin >>start){
        mx = INT_MIN;
        cin>>end;

        solve(start,end);
        cout <<start <<" " << end << " " <<  mx << endl;
    }
}