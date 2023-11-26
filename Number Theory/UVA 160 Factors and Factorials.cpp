/*
 * Problem link: https://vjudge.net/problem/UVA-160
 * */

#include <bits/stdc++.h>
using namespace std;

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

int pPowerinNFactorial(int n, int p) {
    int pow = 0;
    for(int i = p; i <= n ; i = i * p)
        pow += n/i;

    return pow;
}


int main(){
    int n;
    vector<int> primes;
    sieve(105,primes);

    while(cin >> n , n != 0){
        cout <<setw(3) << right <<  n <<"! =";
        vector<int> res;
        
        for(int prime: primes){
            res.push_back(pPowerinNFactorial(n,prime));
        }
        int lastFactor = res.size()-1;
        while(res[lastFactor]==0)lastFactor--;

        // **Strange Output format**
        for (int i = 0; i <= lastFactor; ++i) {
            if((i) % 15 == 0 && i!=0) cout <<"      ";
            cout << setw(3) << res[i];
            if((i+1) % 15 == 0)cout <<"\n";
        }
        if((lastFactor+1) % 15 != 0)cout << endl;
    }
}