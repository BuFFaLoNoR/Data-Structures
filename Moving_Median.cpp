#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int return_median(vector<int> v) {
    if (v.size()%2 == 0) {
        return (v[v.size()/2] + v[(v.size()/2)-1])/2;
    } else {
        return (v[v.size()/2]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> check;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<=m; i++) {
        check.push_back(v[i]);
    }
    sort(check.begin(),check.end());
    cout << return_median(check) << " ";
    for (int i=1; i<v.size()-m; i++) {
        check.erase(find(check.begin(), check.end(), v[i-1]));
        check.push_back(v[i+m]);
        sort(check.begin(), check.end());
        cout << return_median(check) << " ";
    }

    return 0;
}