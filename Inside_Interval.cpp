#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int N,M;
    cin >> N >> M;
    map<int,int> m;
    for (int i=0; i<N; i++) {
        int ini,f;
        cin >> ini >> f;
        m[f] = ini;
    }
    for (int i=0; i<M; i++) {
        int check;
        cin >> check;
        auto it = m.lower_bound(check);
        if (it == m.end() || check < it->second ) {
            cout << 0 << " ";
        } else {
            cout << 1 << " ";
        }
    }

    return 0;
}