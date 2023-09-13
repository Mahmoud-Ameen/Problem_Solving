//
// Problem link: https://codeforces.com/contest/489/problem/C
// Greedy
//

#include <bits/stdc++.h>
using namespace std;

string getMax(int target, int digits){
    if(digits == 0){return "";};

    for (int i = min(9,target); i >= 0; --i) {
        if(i<=target)
            return to_string(i) + getMax(target - i, digits - 1);
    }
}

string getMin(int target, int digits, bool isFirst){

    if(digits == 0){return "";};
    for (int i = min(0 + isFirst, target); i <= 9; ++i) {
        if(i<=target && 9*(digits-1) >= target -i)
            return to_string(i) + getMin(target - i, digits - 1, false);
    }
}

int main(){
    int m,s;
    cin >>m >>s;

    if(9*m < s || (s == 0&&m!=1)) cout << "-1 -1\n";
    else
        cout << getMin(s, m, true) << " " << getMax(s, m) << endl;
}