#include<iostream>

using namespace std;

int main() {
    int used; cin >> used;
    int check = 1;
    while (check < used) {
        check *= 2;
    }
    cout << check-used << endl;
    return 0;
}