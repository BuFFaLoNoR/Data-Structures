#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE
  //DON"T FORGET TO RETURN THE RESULT
  stack<int> calculate;
  for(auto i:v) {
    if (i.first == 1) {
      calculate.push(i.second);
    } else {
      if (i.second == 0) {
        if (calculate.size() >= 2) {
          int c1,c2;
          c1 = calculate.top(); calculate.pop();
          c2 = calculate.top(); calculate.pop();
          calculate.push(c2+c1);
        } else {
          return calculate.top();
        }
      } else if (i.second == 1) {
        if (calculate.size() >= 2) {
          int c1,c2;
          c1 = calculate.top(); calculate.pop();
          c2 = calculate.top(); calculate.pop();
          calculate.push(c2-c1);
        } else {
          return calculate.top();
        }
      } else if (i.second == 2) {
        if (calculate.size() >= 2) {
          int c1,c2;
          c1 = calculate.top(); calculate.pop();
          c2 = calculate.top(); calculate.pop();
          calculate.push(c2*c1);
        } else {
          return calculate.top();
        }
      } else if (i.second == 3) {
        if (calculate.size() >= 2) {
          int c1,c2;
          c1 = calculate.top(); calculate.pop();
          c2 = calculate.top(); calculate.pop();
          calculate.push(c2/c1);
        } else {
          return calculate.top();
        }
      }
    }
  }
  return calculate.top();
}

#endif