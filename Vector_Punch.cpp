#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
 //write some code here
 //don’t forget to return something
    vector <string> ans;
    int start = distance(v.begin(),it) - k;
    int end = distance(v.begin(),it) + k;
    if (start < 0) {
        start = 0;
    }
    if (end > v.size()) {
        end = v.size();
    }
    for (int i = 0; i < v.size(); i++) {
        if (i < start || i > end) {
            ans.push_back(v[i]);
        }
    }
    return ans;
}
int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0;i < n;i++) {
    cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result) {
        cout << x << endl;
    }
}