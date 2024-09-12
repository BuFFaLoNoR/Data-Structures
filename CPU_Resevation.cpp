#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    map <int,int> ans;
    for (int i=0; i<n; i++) {
        int s,f;
        cin >> s >> f;
        auto it = ans.lower_bound(s);
        if (it == ans.end() || f < it->first) {
            ans[f] = s;
            cout << i+1 << " ";
        }
    }

    return 0;
}