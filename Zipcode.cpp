#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Letter
{
public:
    string name;
    string address;
    string province;
    string district;
    int zip;
    bool operator<(const Letter &other) const
    {
        //**Begin Insert**
        if (zip < other.zip) {
            return true;
        } else if (zip > other.zip) {
            return false;
        } else {
            if (address < other.address) {
                return true;
            } else if (address > other.address) {
                return false;
            } else {
                if (district < other.district) {
                    return true;
                } else if (district > other.district) {
                    return false;
                } else {
                    if (province < other.province) {
                        return true;
                    } else if (province > other.province) {
                        return false;
                    } else { 
                        if (name < other.name) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        //**End Insert**
    }
};
class ZipInfo
{
public:
    int zip;
    string province;
    string district;
};
void correctZipAndSortLetters(vector<ZipInfo> &zipinfo, vector<Letter> &letters)
{
    //**Begin Insert**
    map<string,int> m;
    for (auto &i:zipinfo) {
        m[i.district] = i.zip;
    }
    for (auto &i:letters) {
        if (m[i.district] != i.zip) {
            i.zip = m[i.district];
        }
    }
    sort(letters.begin(),letters.end());
    //**End Insert**
}
int main()
{
    int nzip;
    cin >> nzip;
    vector<ZipInfo> zipinfo;
    for (int i = 0; i < nzip; i++)
    {
        ZipInfo z;
        cin >> z.zip >> z.district >> z.province;
        zipinfo.push_back(z);
    }
    int n;
    cin >> n;
    vector<Letter> letters;
    for (int i = 0; i < n; i++)
    {
        Letter l;
        cin >> l.name >> l.address >> l.district >> l.province >> l.zip;
        letters.push_back(l);
    }
    correctZipAndSortLetters(zipinfo, letters);
    for (auto &l : letters)
    {
        cout << l.name << " " << l.address << " " << l.district << " " << l.province << " " << l.zip << endl;
    }
}