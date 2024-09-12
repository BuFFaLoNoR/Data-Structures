#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N,M,A;
    cin >> N >> M >> A; 
    map<int,int> item;
    map<int,map<int,int>> user;
    map<int,vector<int>> ans;

    for (int i=1; i<N+1; i++) {
        int quantity; cin >> quantity;
        item[i] = quantity;
    }
    for (int i=1; i<=M; i++) {
        user[i];
        ans[i];
    }
    for (int i=0; i<A; i++) {
        char act;
        cin >> act;
        int label,label_item,money;
        if (act == 'B') {
            cin >> label >> label_item >> money;
            user[label][label_item] = money;
        } else {
            cin >> label >> label_item;
            user[label][label_item] = 0;
        }
    }
    for (auto &i:item) {
        vector<pair<int,int>> check;
        for (auto &j:user) {
            check.push_back({user[j.first][i.first], j.first});
        }
        sort(check.begin(),check.end());
        for (int c=0; c<i.second; c++) {
            auto max = max_element(check.begin(),check.end());
            if (max != check.end() && max->first > 0) {
                ans[max->second].push_back(i.first);
                max->first = 0;
                user[max->second][i.first] = 0; 
            } else {
                break;
            }
        }
    }
    for (auto &u:ans) {
        if (!u.second.empty()) {
            for (auto &items:u.second) {
                cout << items << " ";
            }
            cout << endl;
        } else {
            cout << "NONE" << endl;
        }
    }
    return 0;
}