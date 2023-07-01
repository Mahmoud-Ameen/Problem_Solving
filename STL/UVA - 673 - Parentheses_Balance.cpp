/*
 * problem link: https://vjudge.net/problem/UVA-673
 * */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){

  int t;
  cin >> t;
  string s;

  cin.ignore();
  while(t--){
    getline(cin,s);

    stack<char> st;
    for (char ch : s)
    {
      bool isOpeningBracket = ch == '(' || ch == '[';
      if (isOpeningBracket)
        st.push(ch);

      else if (st.empty()) {
          // invalid case
          // push any character to the stack so that it won't be empty
          st.push('m');
          break;
      }
      else if (ch == ')' && st.top() == '(' ||
              ch == ']' && st.top() == '[')
        st.pop();

      else break;
    }
    if (st.empty()) cout << "Yes\n";
    else cout << "No\n";
  }
}