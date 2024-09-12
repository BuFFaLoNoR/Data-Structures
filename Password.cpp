#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

char change_char(char x, int k) {
    int new_pos = x - 'a' + k;
    if (new_pos % 26 < 0) {
        new_pos += 26;
        new_pos %= 26;
    } else {
        new_pos %= 26;
    }
    return 'a' + new_pos;
}

string change_string(string s, vector<int> add) {
    string ans;
    int c = 0;
    for (char i:s) {
        ans += change_char(i,add[c]);
        c++;
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int N,M,L;
    cin >> N >> M >> L;
    vector<int> add;
    set<string> after;
    vector<string> ans;
    vector<string> before(M);
    for (int i=0; i<L; i++) {
        int l;
        cin >> l;
        add.push_back(l);
    }
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        after.insert(s);
    }
    for (int i=0; i<M; i++) {
        cin >> before[i];
    }
    for (auto &s:before) {
        ans.push_back(change_string(s,add));
    }
    for (auto &s:ans) {
        if (after.find(s) != after.end()) {
            cout << "Match" << '\n';
        } else {
            cout << "Unknown" << '\n';
        }
    }
    return 0;
}