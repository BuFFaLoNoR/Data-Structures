#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int N; cin >> N;
    set<string> ans;
    for (int i=0; i<N; i++) {
        string input; cin >> input;
        ans.insert(input);
    }
    for (auto joke:ans) {
        cout << joke << endl;
    }
}