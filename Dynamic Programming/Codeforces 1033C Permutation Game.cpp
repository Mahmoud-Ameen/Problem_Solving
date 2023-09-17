/*
 * Problem link: https://codeforces.com/contest/1033/problem/C
 * Rate: 1600
 * */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cards;
vector<int> dp(1e5+1,-1);
bool canWin(int i){

    if(dp[i] != -1) return dp[i];

    for (int j = i+cards[i]; j < n; j+=cards[i]) {
        if(cards[j] > cards[i]) {
            if(!canWin(j)) return dp[i] = true;
        }
    }

    for (int j = i - cards[i]; j >= 0; j-=cards[i]) {
        if(cards[j] > cards[i]) {
            if(!canWin(j)) return dp[i] = true;
        }
    }

    return dp[i] = false;
}

int main(){
    cin>>n;

    cards.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>cards[i];
    }

    for (int i = 0; i < n; ++i) {
        if(canWin(i)) cout << "A";
        else cout << "B";
    }
}