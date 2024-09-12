#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {1,2,3,4};
    set<int> s1 = {1,2,3};
    set<int> s2 = {1,2,3,4};
    bool check = v1 < v2;
    bool check1 = s1 < s2;
    cout << check << " " << check1 <<
}