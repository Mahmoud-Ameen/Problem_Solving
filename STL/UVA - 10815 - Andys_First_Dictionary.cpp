/*
 * ploblem link: https://vjudge.net/problem/UVA-10815
 * */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> *getWords(string &s)
{
  auto v = new vector<string>;
  int d = 'a' - 'A';

  string word;
  for (char ch : s)
  {
    if (ch >= 'A' && ch <= 'Z')
      word.push_back(ch + d);

    else if (ch >= 'a' && ch <= 'z')
      word.push_back(ch);

    // any non-alphabetic character in this problem is considered as a delimiter
    else if (!word.empty())
    {
      v->push_back(word);
      word = "";
    }
  }
  if (!word.empty())
  {
    v->push_back(word);
    word = "";
  }

  return v;
}

int main()
{

  string s;
  set<string> dict;

  while (cin >> s)
  {
    auto words = *getWords(s);
    for (auto word : words)
    {
      dict.insert(word);
    }
  }
  for (auto i : dict)
  {
    cout << i << endl;
  }
}