/*
 * Problem Link: https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628
 * */

#include <bits/stdc++.h>
using namespace std;

int countPartitions(int n, int d, vector<int> &arr) {
    sort (arr.begin(),arr.end());
    int maxSum = 2500;

    vector<int> prevDp(maxSum+1);
    vector<int> currDp(maxSum+1);

    prevDp[0] = 1;
    for (int index = 0; index < n; ++index) {
        int num = arr[index];
        for (int sum = 0; sum <= maxSum; ++sum) {
            currDp[sum] = prevDp[sum];

            if(sum - num >= 0) {
                currDp[sum] += prevDp[sum-num];
                currDp[sum] %= int(1e9+7);
            }
        }
        swap(prevDp,currDp);
    }

    int totalSum = 0;
    for (int& num: arr)
        totalSum+=num;

    int answer = 0;
    for (int s1 = 0; s1 <= totalSum; ++s1) {
        int s2 = totalSum - s1;

        if(s1-s2 == d) answer+=prevDp[s1];
    }

    return answer;
}
