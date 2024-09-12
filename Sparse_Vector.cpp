#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int, int> &v, int pos, int value)
{
    // your code here
    auto lowest = v.lower_bound(pos);
    int j = v.size() - distance(v.begin(),lowest);
    vector<pair<int,int>> ans = {{pos,value}};
    for (auto i = lowest; i!=v.end(); i++) {
        ans.push_back({i->first+1,i->second});
    }
    v.erase(lowest,v.end());
    for(auto pair:ans) {
        v.insert(v.end(),pair);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int, int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        insert_into_sv(v, a, b);
    }
    cout << v.size() << "\n";
    for (auto &x : v)
    {
        cout << x.first << ": " << x.second << "\n";
    }
}