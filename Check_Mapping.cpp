#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> f1;
    set<int> f2;
    for (int i=1; i<=N; i++) {
        int l;
        cin >> l;
        f1.insert(i);
        f2.insert(l);
    }
    set<int>::iterator it1 = f1.begin();
    set<int>::iterator it2 = f2.begin();
    bool oto = true;
    while (it1!=f1.end()) {
        if (f1.size() != f2.size() || *it1 != *it2) {
            oto = false;
            break;
        } else {
            it1++;
            it2++;
        }
    }
    if (!oto) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}