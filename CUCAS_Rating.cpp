#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

int main() {
    cout << std::fixed << std::setprecision(2);
    int N;
    cin >> N;
    map<string,pair<int,int>> m_count;
    map<string,pair<int,int>> m_point;
    for (int i=0; i<N; i++) {
        string number;
        string name;
        int rating;
        cin >> number >> name >> rating;
        if (m_count[number].first == 0) {
            m_count[number].first++;
            m_count[number].second += rating;
        } else {
            m_count[number].first++;
            m_count[number].second += rating;
        }
        if (m_point[name].first == 0) {
            m_point[name].first++;
            m_point[name].second += rating;
        } else {
            m_point[name].first++;
            m_point[name].second += rating;
        }
    }
    for (auto i:m_count) {
        cout << i.first << " " << (i.second.second + 0.0)/i.second.first << endl;
    }
    for (auto i:m_point) {
        cout << i.first << " " << (i.second.second + 0.0)/i.second.first << endl;
    }
}