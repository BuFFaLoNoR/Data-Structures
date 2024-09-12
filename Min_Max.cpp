#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    int M; cin >> M;
    int matrix[N][M];
    int R; cin >> R;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int l; cin >> l;
            matrix[i][j] = l;
            }
        cout << endl;
    }
    int index[R][4];
    for (int i=0; i<R; i++) {
        for (int j=0; j<4; j++) {
            int l; cin >> l;
            index[i][j] = l;
        }
        cout << endl;
  }
    for (int i=0; i<R; i++) {
        vector <int> v;
        bool check1 = false;
        bool check2 = false;
        if ((index[i][0] > index[i][2]) || ((index[i][1] > index[i][3]))) {
            check1 = true;
        }
        if (((index[i][0] > N) || (index[i][1]) > M)){
            check2 = true;
        }
        if (index[i][2] > N) {
            index[i][2] = N;
        }
        if (index[i][3] > M) {
            index[i][3] = M;
        }
        for (int c1 = index[i][0]-1; c1 < index[i][2]; c1++) {
            for (int c2 = index[i][1]-1; c2 < index[i][3]; c2++) {
                v.push_back(matrix[c1][c2]);
            }
        }
        auto max_value = max_element(v.begin(), v.end());   
        if (check1) {
            cout << "INVALID" << endl;
        } else if (check2) {
            cout << "OUTSIDE" << endl;
        } else {
            cout << *max_value << endl;
        }
    }
}