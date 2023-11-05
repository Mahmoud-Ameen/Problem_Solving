//
// Problem link: https://vjudge.net/problem/UVA-10168
//

// **region Solution**

/*
 * This problem is based on the Goldbach Conjecture
 * the Goldbach Conjecture suggests that every even number (greater than 2)
 * can be represented as a sum of two prime numbers.
 * So our goal is to substract two prime numbers from the given number such that
 * the remaining is even and greater than 2 (thus can be represented as a sum of two primes).
 * To accomplish that, we can subtract 2,2 from the number if it's even and 2,3 if it's odd.
 *
 * Note that the smallest even nubmer that can be represented as a sum of four primes is 8 (2,2,2,2),
 * and the smallest odd number that can be represented as a sum of four primes is 9 (2,2,2,3);
 * so any number less than 8 is impossible to represent in the wanted way.
 */

// endregion

#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;


bool isPrime[int(1e7+5)];
vector<int> primes;
void sieve() {
    int n = 1e7;

    for (int i = 0; i <= n; ++i) isPrime[i] = true;


    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        if(isPrime[i]) primes.push_back(i);
    }
}


int main(){
    sieve();

    int n;
    while(cin >> n){
        int prime1,prime2,prime3,prime4 = -1;
        if(n & 1){
            prime1 = 2;
            prime2 = 3;
            n = n - prime1 - prime2;
        }
        else {
            prime1 =  prime2 = 2;
            n = n - prime1 - prime2;
        }

        for (int prime:primes) {
            if(prime >= n) break;
            if(isPrime[n-prime]){
                prime3 = prime;
                prime4 = n-prime3;
                n-=prime3;
                n-=prime4;

                break;
            }
        }

        if(prime4 == -1 || n < 0)
            cout <<"Impossible.\n";
        else
            cout << prime1 << " " << prime2 << " " << prime3 << " " << prime4 << endl;
    }
}