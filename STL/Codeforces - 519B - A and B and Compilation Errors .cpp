
/*
 * problem link: https://codeforces.com/problemset/problem/519/B
 * */

#include <iostream>
#include <map>
using namespace std;

void readSequence(int n, map<int, int>& occurrences) {
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        occurrences[num]++;
    }
}

int main() {
    int n;
    cin >> n;

    map<int, int> first, second, third;

    readSequence(n, first);
    readSequence(n - 1, second);

    // Compare first with second
    for (const pair<int, int>& firstPair : first) {
        if (firstPair.second > second[firstPair.first]) {
            cout << firstPair.first << endl;
            break;
        }
    }

    readSequence(n - 2, third);

    // Compare second with third
    for (const pair<int, int>& secondPair : second) {
        if (secondPair.second > third[secondPair.first]) {
            cout << secondPair.first << endl;
            break;
        }
    }

    return 0;
}
