#include <iostream>
#include <vector>
using namespace std;
void remove_even(std::vector<int> &v, int start_idx, int end_idx) {
    // Iterate over the specified range and remove even numbers
    vector <int> ans;
    for (int i = 0; i < start_idx; i++) {
        ans.push_back(v[i]);
    }
    for (int i = start_idx; i < end_idx+1; i++) {
        if (i % 2 != 0) {
            ans.push_back(v[i]);
        }
    }
    for (int i = end_idx+1; i < v.size(); i++) {
        ans.push_back(v[i]); 
    }
    v = ans;
}
int main() {
    //read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++) {
    int c;
    cin >> c;
    v.push_back(c);
    }
    cin >> a >> b;
    //call function
    remove_even(v,a,b);
    //display content of the vector
    for (auto &x : v) {
    cout << x << " ";
    }
    cout << endl;
}