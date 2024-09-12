#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> v1(N);
    vector<int> v2(M);
    vector<int> ans;
    for (int i=0; i<N; i++) {
        cin >> v1[i];
    }
    for (int i=0; i<M; i++) {
        cin >> v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int c1=0;
    int c2=0;
    while (c1<v1.size() && c2<v2.size()) {
        if (v1[c1] == v2[c2]) {
            if (find(ans.begin(),ans.end(),v1[c1]) == ans.end()) {
                ans.push_back(v1[c1]);
                c1++;
                c2++;
            } else {
                c1++;
                c2++;
            }

        } else {
            if (v2[c2] > v1[c1]) {
                c1++;
            } else if (v2[c2] < v1[c1]) {
                c2++;
            }
        }
    }
    for (auto i:ans) {
        cout << i << " ";
    }
}