#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m;
    cin >> n >> m;
    int round = 1;
    multiset<int> aj;
    vector<vector<int>> opp; 
    bool lose = false;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        aj.insert(l);
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> v;
        for (int j = 0; j < k; j++) {
            int l; cin >> l;
            v.push_back(l);
        }
        opp.push_back(v);
    }
    for (auto i:opp) {
        for (auto power:i) {
            auto it = aj.upper_bound(power);
            if (it == aj.end()) {
                lose = true;
                break;
            } else {
                aj.erase(it);
            }
        }
        if (lose) {
            cout << round << endl;
            break;
        } else {
            round++;
            if (round > m) {
                cout << round << endl;
                break;
            }
        }
    }
    return 0;
}