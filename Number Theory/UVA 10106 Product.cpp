#include <bits/stdc++.h>
using namespace std;

string product(string& firstNumber, string& secondNumber){
    string res (firstNumber.size() + secondNumber.size(), '0');

    for (int i = int(firstNumber.size() - 1); i >= 0; --i) {
        int carry = 0;
        int digit1 = firstNumber[i] - '0';
        for (int j = int(secondNumber.size() - 1); j >= 0; --j) {
            int digit2 = secondNumber[j] - '0';

            int p = digit1 * digit2 + (res[i + j + 1] - '0') + carry;
            res[i + j + 1] = char(p % 10 + '0');
            carry = p/10;
        }
        res[i] += carry;
    }

    int numberStart = 0;
    while(res[numberStart++]=='0') {
        if(numberStart == res.size()) return "0";
    }

    numberStart--;

    return res.substr(max(0,numberStart));
}

int main(){
    string a,b;
    while(cin >> a >> b){
        cout << product(a,b) << endl;
    }
}