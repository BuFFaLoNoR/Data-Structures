#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  auto newData = new T[mSize*2];
  int c = size()-1; 
  for (int i=0; i<size()*2; i++) {
    if (i < size()) {
      newData[i] = mData[i];
    } else {
      newData[i] = mData[c--];
    }
  }
  delete [] mData;
  mCap = mSize*2;
  mSize = mCap;
  mData = newData;
}
#endif