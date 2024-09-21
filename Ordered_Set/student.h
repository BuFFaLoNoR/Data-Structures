#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<bool> ans(100000);
    vector<T> v;
    for (auto &a:A) {
        ans[a] = true;
        v.push_back(a);
    }
    for (auto &b:B) {
        if (ans[b] == false) {
            v.push_back(b);
            ans[b] = true;
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    vector<bool> ans(100000);
    for (auto &b:B) {
        ans[b] = true;
    }
    for (auto &a:A) {
        if (ans[a] == true) {
            v.push_back(a);
        }
    }
    return v;
}
