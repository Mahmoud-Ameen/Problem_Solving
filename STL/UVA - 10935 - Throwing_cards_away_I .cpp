/*
 * problem link: https://vjudge.net/problem/UVA-10935
 * */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  while (n!=0){
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
      q.push(i);
    }
    cout << "Discarded cards:";
    int sz = n;
    for (int i = 1; i < n; i++)
    {
      cout << " " << q.front();
      if (i != n-1) cout << ",";

      q.pop();
      q.push(q.front());
      q.pop();
    }

    cout << "\n";
    cout << "Remaining card: " << q.front()<<endl;
    
    cin>>n;
  }
}