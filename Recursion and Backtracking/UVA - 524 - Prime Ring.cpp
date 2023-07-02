/*
 * problem link : https://vjudge.net/problem/UVA-524
 * */


#include <bits/stdc++.h>
using namespace std;

int mx;

vector<int> combination;
map<int,bool> primes;
bool used[30];


void findCombination(int prev ) {
    if(combination.size() == mx) {
        if(!primes[combination[mx-1] + 1]) return;

        for (int i = 0;i<mx;i++) {
            int number = combination[i];
            cout << number << (i!=mx-1 ? " " : "");
        }
        cout << endl;
        return;
    }

    for (int i = 2; i <= mx; ++i) {
        if( !used[i] && primes[prev+i]) {

            // start a branch on choosing this number
            used[i] = true;
            combination.push_back(i);
            findCombination(i);

            // revert changes (choose another number)
            combination.pop_back();
            used[i] = false;
        }
    }
}

void solve(){
    combination.clear();
    combination.push_back(1);

    for (int i = 0; i < mx; ++i) {
        used[i] = false;
    }

    findCombination(1);
}

int main(){
    for (auto prime:{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61}) {
        primes[prime] = true;
    }

    int caseNum = 1;
    while(cin >> mx){
        if(caseNum!=1) cout << '\n';
        cout << "Case " <<caseNum<<":\n";
        solve();
        caseNum++;
    }
}