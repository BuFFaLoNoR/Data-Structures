#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>

using namespace std; 

int main() {
    int N;
    map<string,int> m;
    cin >> N;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        m[s]++;
    }
        vector<pair<int,string>> v(m.size());
    int c = 0;
    for (auto i:m) {
        v[c].first = i.second;
        v[c].second = i.first;
        c++; 
    }
    sort(v.begin(),v.end());
    cout << v[v.size()-1].second << " " << v[v.size()-1].first << endl;

    return 0;
}