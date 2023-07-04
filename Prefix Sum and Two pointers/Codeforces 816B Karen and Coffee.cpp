/*
 * problem link: https://codeforces.com/contest/816/problem/B
 * */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k,q;

    cin >> n >> k >> q;
    int arrSZ = 200005;
    int rec[200005]{0};

    /*
     * using cumulative sum we will find how many times was a temp recommended
     * by counting how many intervals started before it and ended after
     * we mark every interval start by incrementing its value in a frequency array,
     * and mark every interval end by decrementing the value after it.
     * this cancels the effect of the opened interval after its closing.
     * */

    for (int i = 1; i <= n; ++i) {
        int left,right;
        cin >> left >> right;

        rec[left]++;
        rec[right + 1]--;
    }

    /*
     * count how many times was a temperature recommended
     * by calculating how many intervals was opened before it and closed after it
     * */
    for(int i = 1;i < arrSZ; ++i){
        rec[i] += rec[i-1];
    }

    /*
     * if this temp was recommended greater than or equal to k times mark it as admissible
     * */
    for(int i = 0;i < arrSZ; ++i){
        rec[i] = ((rec[i] >= k) ? 1 : 0);
    }

    /*
     * using cumulative sum, count how many admissible temperatures exists before each temp
     * */
    for(int i = 1;i < arrSZ; ++i){
        rec[i] += rec[i-1];
    }

    for (int i = 0; i < q; ++i) {
        int a,b;
        cin >> a >>b;
        cout << rec[b] - rec[a-1] << '\n';
    }



}