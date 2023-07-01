/**
 * problem link: https://vjudge.net/problem/UVA-11995
 **/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  while(cin>>n){
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;

    bool isStack = true;
    bool isQueue = true;
    bool isPQueue = true;

    for (size_t i = 0; i < n; i++)
    {
      int command;
      cin >> command;
      int x;
      cin >> x;

      if (command == 1) {
        st.push(x);
        q.push(x);
        pq.push(x);
      }else {
        if(st.empty() || st.top() != x) isStack = false;
        if(q.empty() || q.front() != x) isQueue = false;
        if(pq.empty() || pq.top() != x) isPQueue = false;
        
        if(!st.empty()) st.pop();
        if(!q.empty()) q.pop();
        if(!pq.empty()) pq.pop();
      }
    }

    if (isStack + isQueue + isPQueue == 0) cout <<"impossible\n";
    else if (isStack + isQueue + isPQueue > 1) cout <<"not sure\n";
    else if (isStack) cout << "stack\n";
    else if (isQueue) cout << "queue\n";
    else if (isPQueue) cout << "priority queue\n";
  }
}