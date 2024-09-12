#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v1;
    vector<int> v2;
    for (int i=0; i<n; i++) {
        int l;
        cin >> l;
        v1.push_back(l);
    }
    for (int i=0; i<m; i++) {
        int l;
        cin >> l;
        v2.push_back(l);
    }
    sort(v1.begin(),v1.end());
    for (auto i:v2) {
        int lowest = i-k;
        int highest = i+k;
        auto lower = lower_bound(v1.begin(), v1.end(), lowest);
        auto upper = upper_bound(v1.begin(), v1.end(), highest);
        int c = upper - lower;
        cout << c << " ";
    }
    
    return 0;
}