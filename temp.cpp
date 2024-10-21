#include "temp.h"

template<typename T>
T temp<T>::getA(){
    return a;
}
template<typename T>
void temp<T>::setA(T val){
    a = val;
}
template class temp<int>;