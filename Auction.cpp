#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N,M,A;
    cin >> N >> M >> A; 
    vector<vector<int>> item(N, vector<int>(M));
    vector<set<int>> ans(N, set<int>());

    for (int i=0; i<N; i++) {
        int quantity; cin >> quantity;
        item[i][0] = quantity;
    }
    for (int i=0; i<A; i++) {
        char act;
        cin >> act;
        int label,label_item,money;
        if (act == 'B') {
            cin >> label >> label_item >> money;
            item[label_item-1][label] = money;
        } else {
            cin >> label >> label_item;
            item[label_item-1][label] = 0;
        }
    }
    for (int i=0; i<item.size(); i++) {
        auto max = max_element(item[i].begin(), item[i].end());
        while (item[i][0] > 0 && *max > 0) {
            int d = distance(item[i].begin(), max) - 1;
            item[i][0]--;
            ans[i].insert(d);
            *max = 0;
            auto max = max_element(item[i].begin(), item[i].end());
        }
    }
    for (auto s:ans) {
        if (!s.empty()) {
            for (auto i:s) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << "NONE" << endl;
        }
    }
    return 0;
}