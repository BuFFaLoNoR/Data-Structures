#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v;
    int Q; cin >> Q;
    for (int i=0; i<Q; i++) {
        int l;
        string com; cin >> com;
        if (com != "sa" && com != "sd" && com != "r") {
            cin >> l;
        }
        if (com == "pb") {
            v.push_back(l);
        } else if (com == "sa") {
            sort(v.begin(),v.end());
        } else if (com == "sd") {
            vector<int> rsort;
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
        } else if (com == "d") {
            v.erase(v.begin()+l);
        } else if (com == "r") {
            vector<int> rsort;
            int c = 0;
            reverse(v.begin(), v.end());
        }
    }
    for (auto m:v) {
        cout << m << " ";
    }
}