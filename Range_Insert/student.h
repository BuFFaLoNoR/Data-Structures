#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  auto newData = new T[size()+(last-first)];
  size_t pos = 0;
  auto it = begin();
  while (it != position) {
    newData[pos++] = *it;
    it++;
  }
  auto it1 = first;
  while (it1 != last) {
    newData[pos++] = *it1;
    it1++;
  }
  while (it != end()) {
    newData[pos++] = *it;
    it++;
  }
  delete [] mData;
  mData = newData;
  mSize = pos;
  mCap = mSize;
}

#endif
