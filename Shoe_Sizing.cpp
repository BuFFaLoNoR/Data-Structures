#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M;
    set<int> stock;  // Using set instead of vector for faster lookups
    vector<int> client;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int l;
        cin >> l;
        stock.insert(l);  // Directly inserting into set
    }

    for (int i = 0; i < M; i++) {
        int l;
        cin >> l;
        client.push_back(l);
    }

    // Calculate the maximum element just once
    int maxStock = *stock.rbegin();

    for (int i = 0; i < client.size(); i++) {
        int target = client[i];
        auto v = stock.lower_bound(target);

        if (v != stock.end() && *v == target) {
            // If the exact element is found
            cout << *v << " ";
        } else {
            if (v != stock.end()) {
                if (v != stock.begin()) {
                    auto prev = --stock.lower_bound(target);
                    if (abs(target - *prev) < abs(target - *v)) {
                        cout << *prev << " ";
                    } else if (abs(target - *prev) > abs(target - *v)) {
                        cout << *v << " ";
                    } else {
                        cout << *v << " ";
                    }
                } else {
                    cout << *v << " ";
                }
            } else {
                auto max = max_element(stock.begin(),stock.end());
                cout << *max << " ";
            }
        }
    }
    return 0;
}