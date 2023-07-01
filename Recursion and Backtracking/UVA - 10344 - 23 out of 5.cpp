/*
 * problem link: https://vjudge.net/problem/UVA-10344
 * */

#include <bits/stdc++.h>
using namespace std;

vector<int> nums;

bool solveBacktrack( int index, int total) {

    // terminal condition
    if (index >= 5 ) {
        return total == 23;
    }

    // start a branch where we add current number
    if(solveBacktrack( index + 1, total + nums[index])) return true;

    // start a branch where we subtract current number
    if(solveBacktrack( index + 1, total - nums[index])) return true;

    // start a branch where we multiply current number
    if(solveBacktrack( index + 1, total * nums[index])) return true;

    return false;

}

bool solve(){

    sort(nums.begin(),nums.end());

    do {
        if (solveBacktrack(1, nums[0])) return true;
    }while(next_permutation(nums.begin(),nums.end()));

    return false;
}

int main() {

    while (true)
    {
        nums.clear();
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        nums.push_back(a);
        nums.push_back(b);
        nums.push_back(c);
        nums.push_back(d);
        nums.push_back(e);

        if (!nums[0] && !nums[1] && !nums[2] && !nums[3] && !nums[4])
          break;

        bool isPossible = solve();
        cout << (isPossible ? "Possible\n" : "Impossible\n");
    }
}