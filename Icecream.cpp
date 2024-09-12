#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m,start;
    cin >> n >> m >> start;
    vector<pair<int,int>> date;
    vector<pair<int,int>> question;
    for (int i=0; i<n; i++) {
        int a,s;
        cin >> a >> s;
        date.push_back({a,s});
    }
    sort(date.begin(),date.end());
    for (int i=0; i<m; i++) {
        int p,x;
        cin >> p >> x;
        question.push_back({p,x});
    }
    for (auto &value:question) {
        int p = value.first;
        int x = value.second;
        int c = 0;
        int plus = start;
        bool enough = false;
        pair<int,int> ans = {0,0}; //ans.first = date, ans.second = money;
        while (ans.second < p) {
            if (date.empty()) {
                if (ans.first!=x) {
                    ans.second += plus;
                    if (ans.second >= p) {
                        break;
                    } else {
                        ans.first++;
                    }
                } else {
                    ans.second += plus;
                    if (ans.second >= p) {
                        break;
                    } else {
                        ans.second += plus;
                        if (ans.second >= p) {
                            break;
                        } else {
                            ans.second = 0;
                            ans.first++;
                        }
                    }
                }
            } else if (ans.first != date[c].first && ans.first != x && c<date.size()) {
                ans.second += plus;
                if (ans.second >= p) {
                    break;
                } else {
                    ans.first++;
                }
            } else if (ans.first == date[c].first && ans.first != x && c<date.size()) {
                plus = date[c].second;
                ans.second += plus;
                c++;
                if (ans.second >= p) {
                    break;
                } else {
                    ans.first++;
                }
            } else if (c==date.size() && ans.first != x) {
                ans.second += plus;
                if (ans.second >= p) {
                    break;
                } else {
                    ans.first++;
                }
            } else if (c==date.size() && ans.first == x) {
                ans.second += plus;
                if (ans.second >= p) {
                    break;
                } else {
                    ans.second = 0;
                    ans.first++;
                }
            } else if (ans.first != date[c].first && ans.first == x && c<date.size()) {
                ans.second += plus;
                if (ans.second >= p) {
                    break;
                } else {
                    ans.second = 0;
                    ans.first++;
                }
            } else if (ans.first == date[c].first && ans.first == x && c<date.size()) {
                plus = date[c].second;
                ans.second += plus;
                c++;
                if (ans.second >= p) {
                    break;
                } else {
                    ans.second = 0;
                    ans.first++;
                }
            }
        }
        cout << ans.first << " ";
    }

    return 0;
}