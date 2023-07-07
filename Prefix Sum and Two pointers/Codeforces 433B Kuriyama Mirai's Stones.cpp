/*
 * Problem link: https://codeforces.com/problemset/problem/433/B
 * */

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    /* read numbers
     * note that we store ith number in index i of the array */
    int nums[n+1];
    nums[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    /*
     * find cumulative sum of the array
     * */
    long long sums[n+1];
    sums[0] = 0;
    for (int i = 1; i < n+1; ++i) {
        sums[i] = nums[i] + sums[i-1];
    }

    /*
     * sort the array in ascending order and
     * find the cumulative sum according to the new ordering
     * */

    long long sortedSums[n+1];
    sortedSums[0] = 0;
    sort(nums,nums + (n + 1));
    for (int i = 1; i < n+1; ++i) {
        sortedSums[i] = nums[i] + sortedSums[i-1];
    }


    int queries;
    cin >> queries;
    for (int query = 0; query < queries; ++query) {
        int type , l, r;
        cin >> type  >> l >> r;

        if(type == 1)
            cout << sums[r] - sums[l-1] << '\n';
        else
            cout << sortedSums[r] - sortedSums[l-1] << '\n';
    }

}