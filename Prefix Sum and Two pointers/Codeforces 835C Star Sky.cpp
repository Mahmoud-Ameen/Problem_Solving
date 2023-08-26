//
// Created by MAHMOUD on 8/26/2023.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q,c;
    cin >> n >> q >> c;

    int prefixes[11][105][105];
    for (auto & prefixe : prefixes) {
        for (auto & j : prefixe) {
            for (int & k : j) {
                k = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int x,y,s;
        cin >>x>>y>>s;

        prefixes[s][x][y]++;
    }

    for (int s = 0; s <= c; ++s) {
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j <= 100; ++j) {
                prefixes[s][i][j]+=prefixes[s][i][j-1] + prefixes[s][i-1][j] -prefixes[s][i-1][j-1];
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int t,bottom,left,top,right;
        cin >> t >> bottom >> left >> top >> right;

            long long ans = 0;
        for (int s = 0; s <= c; ++s) {
            int bright = (s+t) % (c + 1);
            ans+=
                    (prefixes[s][bottom][right] - prefixes[s][bottom][left-1] - prefixes[s][top-1][right]
                     + prefixes[s][top-1][left-1]) * bright;

        }
        cout << ans <<endl;

    }

}