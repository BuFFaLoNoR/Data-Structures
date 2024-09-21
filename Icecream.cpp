#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,start;
    cin >> n >> m >> start;
    vector<pair<int,int>> date;
    vector<int> day(100000);
    for (int i=0; i<n; i++) {
        int a,s;
        cin >> a >> s;
        date.push_back({a,s});
    }
    sort(date.begin(),date.end());
    auto it = date.begin();
    int plus = start;
    int sum = start;
    day[0] = start;
    for (int i=1; i<100000; i++) {
        if (it != date.end()) {
            if (it->first != i) {
                sum += plus;
                day[i] = sum;
            } else {
                plus = it->second;
                sum += plus;
                day[i] = sum;
                it++;
            }
        } else {
            sum += plus;
            day[i] = sum;
        }
    }
    for (int i=0; i<m; i++) {
        int p,x;
        cin >> p >> x;
        auto check = lower_bound(day.begin(), day.end(), p);
        if (distance(day.begin(), check) <= x) {
            cout << distance(day.begin(), check) << " ";
        } else {
            cout << distance(day.begin(), lower_bound(day.begin(), day.end(), p+day[x])) << " ";
        }
    }
    return 0;
}