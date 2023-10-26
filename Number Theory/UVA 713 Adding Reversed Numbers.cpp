#include <bits/stdc++.h>
using namespace std;

string truncLeadingZeros(string s){
    int numberStart = 0;
    while(s[numberStart++] == '0'){};

    return s.substr(numberStart-1);
}

string addStrings(string a, string b){
    int carry = 0;
    int maxLength = max(a.length(), b.length());
    string result;
    result.reserve(maxLength + 1);

    for (int i = 1; i <= maxLength; ++i) {
        int digit1 = ((a.size()  >= i) ? a[a.size() - i] - '0' : 0);
        int digit2 = ((b.size() >= i) ? b[b.size() - i] - '0' : 0);

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;

        result.insert(result.begin(), static_cast<char>(sum + '0'));
    }

    if (carry > 0) {
        result.insert(result.begin(), static_cast<char>(carry + '0'));
    }

    return result;}

int main(){
    int t;
    cin >> t;
    string a,b;
    while(t--){
        cin >> a >> b;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        string sum = addStrings(a, b);
        reverse(sum.begin(),sum.end());

        cout << truncLeadingZeros(sum) << endl;
    }
}