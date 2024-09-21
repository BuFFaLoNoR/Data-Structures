#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    multiset<int> price;
    for (int i=0; i<N; i++) {
        char input; cin >> input;
        if (input == 'P') {
            int money; cin >> money;
            price.insert(money);
        } else {
            if (!price.empty()) {
                auto it = max_element(price.begin(), price.end());
                cout << *it << endl;
                price.erase(it);
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}