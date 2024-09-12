#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int return_median(vector<int> v) {
    map<int,int> count;
    vector<pair<int,int>> for_sort;
    for (int i:v) {
        count[i]++;
    }
    for (auto i:count) {
        for_sort.push_back({i.second,i.first});
    }
    sort(for_sort.begin(),for_sort.end());
    if (*(for_sort.end()-1)).first >  *(for_sort.end()-2).first {
        return 
    }

}


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=n; i<n; i++) {
        cin >> v[n];
    }


    return 0;
}