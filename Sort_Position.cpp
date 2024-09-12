#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int,int>> s;
    for (int i=0; i<n; i++) {
        int l; cin >> l;
        s.push_back(make_pair(l,i));
    }
    sort (s.begin(), s.end());
    for (int i=0; i<n; i++) {
        s[i].first = s[i].second;
        s[i].second  = i+1;
    }
    sort (s.begin(), s.end());
    for (auto &it:s) {
        cout << it.second << " ";
    } 

    return 0;
}