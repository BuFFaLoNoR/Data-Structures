#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {

    int M,N;
    set<int> s1;
    set<int> s2;
    set<int> ans;
    cin >> M; cin >> N;
    for (int i=0; i<M; i++) {
        int l; cin >> l;
        s1.insert(l);
    }
    for (int i=0; i<N; i++) {
        int l; cin >> l;
        s2.insert(l);
    }
    for (auto it = s1.begin(); it != s1.end(); it++) {
        if (s2.find(*it) != s2.end()) {
            ans.insert(*it);
        }
    }
    for (auto c: ans) {
        cout << c << " ";
    }
}