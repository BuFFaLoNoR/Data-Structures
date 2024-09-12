#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> list(N);
    vector<int> check(M);
    for (int i=0; i<N; i++) {
        cin >> list[i];
    }
    for (int i=0; i<M; i++) {
        cin >> check[i];
    }
    sort(list.begin(), list.end());
    for (auto value : check) {
        bool found = false;
        int left = 0, right = N - 1;
        
        while (left < right) {
            int sum = list[left] + list[right];
            if (sum == value) {
                cout << "YES" << endl;
                found = true;
                break;
            } else if (sum < value) {
                left++;
            } else {
                right--;
            }
        }
        if (!found) {
        cout << "NO" << endl;
        }
    }

    return 0;
}