#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sieve(int n, std::vector<int>& primes) {
    std::vector<bool> v(n+1);
    v[0] = v[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (!v[i])
            for (int j = i * i; j <= n; j += i)
                v[j] = true;
    }

    for (int i = 2; i <= n; ++i) {
        if(!v[i]) primes.push_back(i);
    }
}

int main(){

    vector<int> primes;
    primes.reserve(5000);
    sieve(50000,primes);

    int n;
    while(cin>>n && n != 0){
        bool first = true;

        cout << n << " = ";
        if(n < 0) {
            cout << "-1";
            n *= -1;
            first = false;
        }

        for (int prime: primes)
        {
            if(prime*prime > n) break;
            while (n % prime == 0)
            {
                cout << (first ? "" : " x ") << prime;

                first = false;
                n /= prime;
            }
        }
        if(n>1)
            cout << (first ? "" : " x ") << n;

        cout << endl;
    }
}