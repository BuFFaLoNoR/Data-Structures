#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)
  if (this->empty() && !other.empty()) {
    return true;
  } else {
    int i = 0;
    while (i<mSize) {
      if ((*this)[i] < other[i]) {
        return true;
      } else if ((*this)[i] > other[i]) {
        return false;
      } else {
        i++;
        if (i == mSize && mSize < other.mSize) {
          return true;
        } else if (i == other.mSize && other.mSize < mSize) {
          return false;
        } else if (i == mSize && i == other.mSize) {
          return false;
        } else {
          continue;
        }
      }
    }
  }
  return false;
}

#endif