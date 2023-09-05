#include <bits/stdc++.h>

using namespace std;

int findWays(vector<int>& arr, int k)
{
    int MOD = 1e9+7;
    sort(arr.begin(),arr.end());

    int n = int(arr.size());

    int target = k;
    vector<int> prevDp(target + 1,false);
    vector<int> currDp(target + 1,false);

    prevDp[0] = 1;
    for (int index = 0; index < n; ++index) {
        int num = arr[index];
        if(num > target) break;
        for (int miniTarget = 0; miniTarget <= target; ++miniTarget) {
            currDp[miniTarget] = prevDp[miniTarget];

            if(miniTarget >= num && prevDp[miniTarget - num]){
                currDp[miniTarget]+=prevDp[miniTarget-num];
                currDp[miniTarget]%= MOD;
            }
        }
        swap(prevDp,currDp);
    }

    return prevDp[target];
}
