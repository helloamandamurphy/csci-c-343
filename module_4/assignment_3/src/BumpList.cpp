#include "BumpList.h"

template<class T>
BumpList<T>::BumpList() = default;

template<class T>
BumpList<T>::~BumpList() = default;

template<class T>
void BumpList<T>::clear() {

}

template<class T>
void BumpList<T>::transferFrom(BumpList &source) {

}

template<class T>
void BumpList<T>::advance() {

}

template<class T>
BumpList<T>& BumpList<T>::operator=(BumpList const& rhs) = default;

template<class T>
void BumpList<T>::moveToStart() {

}

template<class T>
void BumpList<T>::moveToFinish() {

}

template<class T>
void BumpList<T>::addRightFront(T &x) {

}

template<class T>
void BumpList<T>::removeRightFront(T &x) {

}



template<class T>
void BumpList<T>::replaceRightFront(T &x) {

}

template<class T>
void BumpList<T>::swapRights(BumpList &otherS) {

}

template<class T>
int BumpList<T>::leftLength() {
   return 0;
}

template<class T>
int BumpList<T>::rightLength() {
   return 0;
}


template<class T>
std::optional<T> BumpList<T>::rightFront() {
    return std::optional<T>();
}

template<class T>
std::optional<int> BumpList<T>::find(T elementToFind) {
    auto t =  new std::optional<int>();
    return *t;
}

template<class T>
std::string BumpList<T>::outputBumpList() {
   return "";
}


