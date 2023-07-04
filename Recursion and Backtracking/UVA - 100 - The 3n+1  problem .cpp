/*
 * problem link: https://vjudge.net/problem/UVA-100
 * */

#include <bits/stdc++.h>

using namespace std;

int mx = INT_MIN;

void findCycleLength(int num, int cycleLength){
    bool isEven = num % 2 == 0;
    if(num == 1){
        mx = max(mx,cycleLength + 1);
        return;
    }

    if(isEven)
        findCycleLength(num / 2, cycleLength + 1);
    else
        findCycleLength(num * 3 + 1, cycleLength + 1);

}

void solve(int start,int end){
    for (int i = start; i <= end; ++i) {
        findCycleLength(i, 0);
    }
    for (int i = end; i <= start; ++i) {
        findCycleLength(i, 0);
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