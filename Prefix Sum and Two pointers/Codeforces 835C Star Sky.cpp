/*
 * Problem Link: https://codeforces.com/contest/835/problem/C
 * */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q,c;
    cin >> n >> q >> c;

    // Initialize a 3D array to store cumulative brightness values
    // The array "planes" represents an array of 2D arrays representing cartesian planes.
    // Where ith place in "planes" represents a cartesian plane that contains stars of brightness i.
    int planes[11][105][105];

    // Sets all array elements to zero
    for (auto & plane : planes) {
        for (auto & row : plane) {
            for (int & element : row) {
                element = 0;
            }
        }
    }

    // Read star information and planes array
    for (int i = 0; i < n; ++i) {
        int x,y,s;
        cin >>x>>y>>s;

        planes[s][x][y]++;
    }

    // Calculate cumulative sums for each brightness level
    for (int s = 0; s <= c; ++s) {
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j <= 100; ++j) {
                planes[s][i][j]+= planes[s][i][j - 1] + planes[s][i - 1][j] - planes[s][i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < q; ++i) {

        int t,bottom,left,top,right;
        cin >> t >> top >> left >> bottom >> right;

        long long ans = 0;
        for (int s = 0; s <= c; ++s) {
            // Calculate final brightness of stars that initially had brightness s after t.
            int bright = (s+t) % (c + 1);

            // Calculate brightness sum within the rectangle using cumulative sums
            ans+= (planes[s][bottom][right] - planes[s][bottom][left - 1] - planes[s][top - 1][right]
                     + planes[s][top - 1][left - 1]) * bright;
        }
        cout << ans <<endl;
    }

}