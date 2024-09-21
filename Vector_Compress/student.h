#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    auto newData = new T[mSize];
    std::copy(begin(), end(), newData);
    delete [] mData;
    mData = newData;
    mCap = mSize;
}

#endif
