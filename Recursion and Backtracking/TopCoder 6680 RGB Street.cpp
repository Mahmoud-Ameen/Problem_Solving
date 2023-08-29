/*
 * Problem Link: https://vjudge.net/problem/TopCoder-6680
 *
 * Note that the problem has a more efficient solution using dp memoization,
 * but this solution works just fine with the problem's constraints.
 * */

#include <bits/stdc++.h>

using namespace std;
class RGBStreet {
    int mx = 21;
    int n;

    int red[21];
    int green[21];
    int blue[21];

    int solve(int index, int lastChoice) {
        int cost = INT_MAX;

        if (index >= n) return 0;

        if (lastChoice != 0)
            cost = min(cost, red[index] + solve(index + 1, 0));

        if (lastChoice != 1)
            cost = min(cost, blue[index] + solve(index + 1, 1));

        if (lastChoice != 2)
            cost = min(cost, green[index] + solve(index + 1, 2));

        return cost;
    }

public:
    int estimateCost(vector<string> homes) {
        n = homes.size();
        for (int i = 0; i < n; ++i) {
            istringstream stream(homes[i]);
            stream >> red[i] >> green[i] >> blue[i];
        }
        return solve(0, -1);
    }
};