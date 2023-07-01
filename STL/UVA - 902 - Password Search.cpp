/*
 * problem link: https://vjudge.net/problem/UVA-902
 * */

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{

  int n;
  while (cin >> n)
  {
    map<string, int> mp;
    string s;
    cin >> s;

    int start = 0;
    int sz = s.size();

    // add all substrings as keys in a map
    // and count their number of occurrences
    while (start + n-1 < sz)
    {
      string subString;
      for (size_t i = 0; i < n; i++)
          subString.push_back(s[start + i]);

      if (mp.find(subString) == mp.end())
        mp[subString] = 0;

      mp[subString]++;
      start++;

    }

    /* find most frequent substring */
    int mx = INT_MIN;
    string password;
    for (pair<string, int> p : mp)
    {
      if (p.second > mx)
      {
        mx = p.second;
        password = p.first;
      }
    }

    cout << password << endl;
  }
}