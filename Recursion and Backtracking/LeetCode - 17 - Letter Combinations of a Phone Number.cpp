/*
 * problem link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * */

#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:

    vector<string> letterCombinations(string inputDigits) {
        initLettersMap();
        this->digits = std::move(inputDigits);

        generateCombinations(0,"");
        return solutions;

    }

private:
    /*
     * maps each digit (of type char) to a vector of letters corresponding to the digit on the phone
     * */
    map<char,vector<char>> letters;

    /**/
    void initLettersMap(){
        letters['2'] = {'a','b','c'};
        letters['3'] = {'d','e','f'};
        letters['4'] = {'g','h','i'};
        letters['5'] = {'j','k','l'};
        letters['6'] = {'m','n','o'};
        letters['7'] = {'p','q','r','s'};
        letters['8'] = {'t','u','v'};
        letters['9'] = {'w','x','y','z'};
    }

    /* private Vector of strings to store the solution combinations in */
    vector<string> solutions;

    /* string represents the input string of digits
     * declared globally in the class to avoid unnecessary copying */
    string digits;

    /**
     * @brief enters a recursive call chain to find all possible letter combinations
     * @param inputProgress represents the index of digit in the input
     * @param combination represents a string combination of letters
     * */
    void generateCombinations(int inputProgress, string combination){
        if(inputProgress == digits.size()) {
            if(!combination.empty())
                solutions.push_back(combination);
            return;
        }

        auto currentVector = letters[digits[inputProgress]];

        for (int i = 0; i < currentVector.size(); ++i) {
            int letterIndex = i;

            combination.push_back(currentVector[letterIndex]);
            generateCombinations(inputProgress+1,combination);
            combination.pop_back();
        }

    }
};