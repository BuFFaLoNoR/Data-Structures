#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main() {
    int n,m; cin >> n >> m;
    map<int,int> somchai;
    vector<pair<int,int>> check;
    for (int i=0; i<n; i++) {
        int l; cin >> l;
        somchai[l] = -1;
    }
    for (int i=0; i<m; i++) {
        int l; cin >> l;
        if (l==1) {
            int name, amount; cin >> name >> amount;
            if(somchai[name] != 0) {
                if (somchai[name] == -1) {
                    somchai[name]++;
                    somchai[name] += amount;
                } else {
                    somchai[name] += amount;
                }
            }
        } else {
            
        }
}