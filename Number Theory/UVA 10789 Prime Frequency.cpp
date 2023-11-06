//
// Problem link: https://vjudge.net/problem/UVA-10789
//

#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

const int SIEVE_N = 2005;
vector<bool> isPrime(SIEVE_N, true);
void sieve() {
    int n = SIEVE_N;
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

int main(){
    int testCases;
    cin >> testCases;
    sieve();
    for (int test = 1; test <= testCases; ++test) {
        string inputString;
        cin >> inputString;

        // Record frequency of each character
        vector<int> freq(200,0);
        for (char ch: inputString)
            freq[ch]++;

        // Output
        cout << "Case " << test << ": ";
        bool isEmpty = true;
        for (int j = 0; j < 200; ++j) {
            if(isPrime[freq[j]]) {
                cout << char(j);
                isEmpty = false;
            }
        }
        if(isEmpty) cout << "empty";

        cout << endl;
    }

}
