#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> value;
    queue<int> order1;
    queue<int> order2;
    int s = 0;
    vector<int> sum = {0};
    for (int i=0; i<m; i++) {
        int l; cin >> l;
        value.push_back(l);
    }
    for (int i=0; i<n; i++) {
        int l; cin >> l;
        if (l == 1) { //if input is 1 then add order
            int a,b; cin >> a >> b;
            if (a == 1) {
                order1.push(b);
            } else {
                order2.push(b);
            }
        } else { //if input is 2 then add the money
            if (!order1.empty() && !order2.empty()) {
                if (order1.front() < order2.front()) {
                    s += order1.front();
                    sum.push_back(s);
                    order1.pop();
                } else if (order2.front() < order1.front()) {
                    s += order2.front();
                    sum.push_back(s);
                    order2.pop();
                } else {
                    s += order1.front();
                    sum.push_back(s);
                    order1.pop();
                }
            } else if (!order1.empty()) {
                s += order1.front();
                sum.push_back(s);
                order1.pop();
            } else {
                s += order2.front();
                sum.push_back(s);
                order2.pop();
            }
        }
    }
    for (auto &money:value) { //checking how many times is needed for each value
        auto check = lower_bound(sum.begin(), sum.end(), money);
        if (check != sum.end()) {
            cout << distance(sum.begin(), check) << " "; //if exist print the amount of times
        } else {
            cout << -1 << " "; //else print -1
        }
    }
    return 0;
}