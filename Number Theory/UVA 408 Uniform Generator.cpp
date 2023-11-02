/*
 * Problem link: https://vjudge.net/problem/UVA-408
 * */

#include <bits/stdc++.h>
using namespace std;

int euclideanGCD(int a, int b){
    if (b == 0)
        return a;
    return euclideanGCD(b, a % b);
}

void goodChoice(int steps, int mod){
    cout << setw(10) << right << steps << setw(10) << right << mod << "    " << left << "Good Choice\n\n";
}
void badChoice(int steps, int mod){
    cout << setw(10) << right << steps << setw(10) << right << mod << "    " << left << "Bad Choice\n\n";
}

int main(){
    int steps,mod;
    while(cin >> steps >> mod){
        if (euclideanGCD(steps,mod) == 1)
            goodChoice( steps, mod);
        else
            badChoice( steps, mod);
    }
}