#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void stack_concat(stack<int> &s1, stack<int> &s2)
{
    stack<int> c_s1(s1);
    stack<int> news2;
    stack<int> news1;
    stack<int> ans;
    // write your code only in this function
    int size1 = s1.size();
    int size2 = s2.size();
    for(int i=0; i<size2; i++) {
        news2.push(s2.top());
        s2.pop();
    }
    for(int i=0; i<size1; i++) {
        news1.push(c_s1.top());
        c_s1.pop();
    }
    for(int i=0; i<size2; i++) {
        ans.push(news2.top());
        news2.pop();
    }
    for(int i=0; i<size1; i++) {
        ans.push(news1.top());
        news1.pop();
    }
    s1 = ans;
}
int main()
{
    // read input
    int n, m;
    int c;
    cin >> n >> m;
    stack<int> s1, s2;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        s1.push(c);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c;
        s2.push(c);
    }
    // call the function
    stack_concat(s1, s2);
    // display content of the stack
    cout << "S1 has " << s1.size() << endl;
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    // display content of the stack
    cout << "S2 has " << s2.size() << endl;
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}