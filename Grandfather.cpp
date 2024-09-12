#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,M;
    map<long long,long long> f;
    map<long long,long long> grandf;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        long long father,son;
        cin >> father >> son;
        if (f[son] == 0) {
            f[son] = father;
        }
    }
    for (auto i:f) {
        if (f[i.second] != 0) {
            grandf[i.first] = f[i.second];
        }
    }
    for (int i=0; i<M; i++) {
        long long c1,c2;
        cin >> c1 >> c2;
        if (c1 != c2 && grandf[c1] == grandf[c2] && grandf[c1] != 0 && grandf[c2] != 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}