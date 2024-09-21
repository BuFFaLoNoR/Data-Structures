#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  int check = 0;

  if (a<begin() || a>end() || b<begin() || b>end()) {
    return false;
  }
  
  if (m <= 0) {
    return false;
  }

  while (check < m) {
    if (a+check == b) {
      return false;
    }
    if (b+check == a) {
      return false;
    }
    if (a+check == end() || b+check == end()) {
      return false;
    }
    check++;
  }
  for (int i=0; i<m; i++) {
    std::swap(*(a+i), *(b+i));
  }
  return true;
}

#endif