//
// Problem link: https://vjudge.net/problem/UVA-10650
//

#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;


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
    sieve(32005,primes);

    int low,high;
    while(cin >> low >> high, low || high){
        if(low > high)
            swap(low,high);

        for (int i = 0; i < primes.size()-2; ++i) {
            if(primes[i] < low ) continue;
            if(primes[i+2] > high) break;

            if(primes[i+1]-primes[i] == primes[i+2]-primes[i+1] ){
                // Set started before 'low'
                if(primes[i] - primes[i-1] == primes[i+1] - primes[i]) continue;

                int end = i+2;
                while(end < primes.size()-1 && primes[end+1] - primes[end] == primes[end] - primes[end-1])
                        end++;
                // Set continues after high
                if(primes[end] > high) continue;

                // Complete set lies between 'low' and 'high'
                cout << primes[i] << " " << primes[i+1] <<" " << primes[i+2];
                for (int j = i+3; j <= end; ++j) {
                    cout << " " << primes[j];
                }

                cout << endl;
                i = end-1;

            }
        }

    }

}