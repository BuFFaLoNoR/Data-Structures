#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> check(m,1);
    vector<int> new_power(n);
    set<pair<int,int>> ajdae;
    for (int i=0; i<m; i++) {
        ajdae.insert(make_pair(1,i));
    }
    for (int i=0; i<n; i++) {
        cin >> new_power[i];
    }
    for (int i=0; i<n; i++) {
        int type;
        cin >> type;
        if (check[type] < new_power[i]) {
            ajdae.erase(ajdae.find({check[type],type}));
            check[type] = new_power[i];
            ajdae.insert({new_power[i],type});
        }
        cout << ajdae.begin()->first << " ";
    }
    return 0;
}