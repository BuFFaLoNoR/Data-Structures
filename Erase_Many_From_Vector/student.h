#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  T* newData = new T[mSize-pos.size()];
  size_t p = 0;
  bool ar[mSize] = {false};
  for (int i=0; i<pos.size(); i++) {
    ar[pos[i]] = true;
  }
  for (int i=0; i<mSize; i++) {
    if (ar[i] != true) {
      newData[p++] = (*this)[i];
    }
  }
  delete [] mData;
  mData = newData;
  mSize = p;
  mCap = mSize;
}

#endif
