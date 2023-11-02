/*
 * Problem link:
 * */

#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;


vector<bool> isPrime(65005, true);
void sieveOfEratosthenes() {
    int n = 65005;
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

ll expMod(ll base, ll exp, ll mod){
    if(exp == 1) return base;

    if(exp & 1) {
        exp--;
        ll temp = expMod(base, exp / 2, mod);
        return (((base * temp) % mod) * temp) % mod;
    }

    ll temp = expMod(base, exp / 2, mod);
    return (temp * temp) % mod;
}

bool equationHolds(ll a, ll n){
    return (expMod(a, n, n) == a) ;
}

int main(){
    int num = -1;
    sieveOfEratosthenes();

    while(true){
        cin >> num; if(num == 0) break;

        if(isPrime[num])
            cout << num <<" is normal.\n";
        else {
            bool carmichael = true;

            for (int i = 2; i < num; ++i) {
                if(!equationHolds(i,num))
                {
                    carmichael = false;
                    break;
                }
            }

            if(carmichael)
                cout << "The number " << num << " is a Carmichael number.\n";
            else cout << num <<" is normal.\n";;

        }
    }
}