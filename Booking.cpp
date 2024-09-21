#include<iostream>
#include<set>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<pair<string,string>> stock;
    int n,m; cin >> n >> m;
    for (int i=0; i<n; i++) {
        string flight,seat; cin >> flight >> seat;
        stock.insert(make_pair(flight,seat));
    }
    for (int i=0; i<m; i++) {
        bool check = true;
        int ticket; cin >> ticket;
        vector<pair<string,string>> del;
        for (int j=0; j<ticket; j++) {  
            string flight,seat; cin >> flight >> seat;
            if (stock.find({flight,seat}) != stock.end())  {
                del.push_back(make_pair(flight,seat));
            } else {
                check = false;
            }
        }
        if (check) {
            for(auto pair:del) {
                stock.erase(pair);
            }
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}