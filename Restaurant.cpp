#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main() {
    std::ofstream outputFile("output.txt");
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m; cin >> n >> m;
    vector<pair<int,int>> chef;
    int time = 0;
    for (int i=0; i<n; i++) {
        int l; cin >> l;
        chef.push_back(make_pair(l,l));
    }
    int i = 0;
    while (i<m) {
        if (i<n) {
            outputFile << 0 << endl;
            i++;
        } else {
            time++;
            for (auto value = chef.begin(); value != chef.end(); value++) {
                if (value->second == time && i<m) {
                    value->second += value->first;
                    outputFile << time << endl;
                    i++;
                } else if (i==m) {
                    break;
                } else {
                    continue;
                }
            }
        }
    }
    return 0;
}