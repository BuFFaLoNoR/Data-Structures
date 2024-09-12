#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    map<string,int> m;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        m[s]++;
    }
    vector<pair<int,string>> v(m.size());
    int c = 0;
    for (auto &i:m) {
        v[c].first = i.second;
        v[c].second = i.first;
        c++;
    }
    sort(v.begin(),v.end());
  
    if (v.size() < K) {
        cout << v[0].first << endl;
    } else {
        vector<pair<int, string>>::iterator it = v.end()-K;
        cout << (*it).first << endl;
    }

    return 0;
}