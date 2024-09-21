#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

//you can include any other file here
//you are allow to use any data structure
#include <unordered_set>
#include <algorithm>

using namespace std;

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  unordered_set<T> s;
  T* newData = new T[mCap];
  size_t c = 0;
  for (size_t i = 0; i<mSize; i++) {
    if (s.find(mData[i]) == s.end()) {
      s.insert(mData[i]);
      newData[c++] = mData[i];
    }
  }
  delete [] mData;
  mData = newData;
  mSize = c;
  mCap = mSize;
}

#endif
