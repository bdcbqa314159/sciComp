#ifndef UNIQUE_INSERT_H
#define UNIQUE_INSERT_H

#include <list>

template<typename T>
void unique_insert(std::list<T>& L, const T& j){
    
    typename std::list<T>::iterator iter = L.begin(), last = L.end();
    while (iter != last && *iter < j) ++iter;
    if (iter == last || *iter != j) L.insert(iter, j);
}

#endif
