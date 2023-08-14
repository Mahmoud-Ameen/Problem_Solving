/*
 * problem link: https://leetcode.com/problems/combination-sum-iii/
 * */

#include <utility>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int inputK, int inputN) {
        n = inputN;
        k = inputK;

        findCombinations();

        return solutions;
    }

private:
    vector<vector<int>> solutions;
    vector<int> combination;
    int n;
    int k;

    void findCombinations(){
        findCombinations(1,0);
    }

    void findCombinations(int num ,int sum  ){
        if (sum == n && combination.size() == k) {
            solutions.push_back(combination);
            return;
        }

        if(sum > n || combination.size() == k || num > 9) return;

        combination.push_back(num);
        findCombinations(num + 1,sum + num);

        combination.pop_back();
        findCombinations(num + 1, sum);
    }
};
