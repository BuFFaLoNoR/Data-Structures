#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<int, set<int>> list; // Stores years and their months
    vector<pair<int, int>> v; // Stores the v

    // Read the list of dates
    for (int i = 0; i < n; i++) {
        int year, month;
        cin >> year >> month;
        list[year].insert(month);
    }

    // Read the v
    for (int i = 0; i < m; i++) {
        int year, month;
        cin >> year >> month;
        v.push_back({year, month});
    }

    // Process each info
    for (const auto& info : v) {
        int year = info.first;
        int month = info.second;

        // Check if the exact date is present
        auto it = list.find(year);
        if (it != list.end() && it->second.find(month) != it->second.end()) {
            cout << "0 0 ";
            continue;
        }

        // Find the closest preceding month in the same year
        if (it != list.end()) {
            auto& months = it->second;
            auto prevMonthIt = months.lower_bound(month);
            if (prevMonthIt != months.begin()) {
                --prevMonthIt;
                cout << year << " " << *prevMonthIt << " ";
                continue;
            }
        }

        // Find the closest preceding year and month
        auto yearIt = list.lower_bound(year);
        if (yearIt == list.begin()) {
            // No preceding year exists
            cout << "-1 -1 ";
        } else {
            --yearIt;
            int prevYear = yearIt->first;
            auto& months = yearIt->second;
            if (!months.empty()) {
                cout << prevYear << " " << *months.rbegin() << " ";
            } else {
                cout << "-1 -1 ";
            }
        }
    }

    return 0;
}