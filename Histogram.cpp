#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<string,int> m;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        m[s]++;
    }
    for (auto i:m) {
        if (i.second > 1) {
            cout << i.first << " " << i.second << endl;
        }
    }

    return 0;
}
