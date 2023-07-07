/*
 * Problem link: https://codeforces.com/contest/251/problem/A
 * */


#include <iostream>
#include <map>

using namespace std;

/* pseudocode for solving the problem:
 * for each number:
 *      find the furthest number where distance <= d
 *      find number of 3-elements combinations in this group
 *      find the intersection between this group and the previous group
 *      calc repeated combinations number
 *      subtract repeated combinations from total combs in this gp
 *      add this gp's unique combinations to total sum
 * */

/* n is the array size
 * d is the max distance between smallest and greatest number*/
int n,d;

/*
 * combinationsPerGroupSz is a map that is used to store the number of combinations in a group depending on group's size
 * to avoid solving the same problem multiple times
 * */
map<int,long long> combinationsPerGroupSz;

/*
 * routine finds the index of the last element within distance [d] in array [nums] of size [n]
 * [previousEndIndex] represents the last element that was already checked in the previous function call
 * since the array is sorted, it is guaranteed that any number that was within the range with the previous number
 * will be within the range with this number. so we can start searching from that index
 * */
int findFurthestElementInRange(const int nums[],int startIndex,int previousEndIndex){
    int index;
    int startNum = nums[startIndex];

    for (int j = previousEndIndex; j < n; ++j) {
        if(nums[j] - startNum > d) break;

        index = j;
    }

    return index;
}

/*
 * returns number of combinations of [combinationSize] elements in a group of [gpSize] elements
 * */
long long combinations(int gpSize,int combinationSize){
    // check if the solution was already found and stored in the map
    if(combinationsPerGroupSz.find(gpSize) != combinationsPerGroupSz.end()) return  combinationsPerGroupSz[gpSize];

    long long sum = 1;

    if(combinationSize > gpSize) return 0;

    // Calculate the value of n choose r using the binomial coefficient formula
    for(int i = 1; i <= combinationSize; i++){
        sum = sum * (gpSize - combinationSize + i) / i;
    }

    combinationsPerGroupSz[gpSize] = sum;
    return sum;
}

int main(){
    cin >> n >> d;

    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long answer = 0;

    int previousGpEnd = 0;
    for (int startIndex = 0; startIndex < n; ++startIndex) {

        // find the furthest number where distance <= d
        int gpEndIndex = findFurthestElementInRange(nums, startIndex,previousGpEnd);

        int gpSize = gpEndIndex - startIndex + 1;
        if(gpSize >= 3 ){

            // find number of 3-elements combinations in this group
            long long combs = combinations(gpSize, 3);

            // find the intersection between this group and the previous group
            int intersectionSz = gpSize - (gpEndIndex - previousGpEnd) ;

            // calc repeated combinations number
            long long repeatedCombs = combinations(intersectionSz,3);

            // subtract repeated combs from total combs in this gp
            combs-=repeatedCombs;

            // add this gp's combs to total sum
            answer+=combs;

        }

        previousGpEnd = gpEndIndex;
        // reached the end of the numbers array
        if(gpEndIndex == n-1) break;

    }

    cout << answer <<'\n';

}