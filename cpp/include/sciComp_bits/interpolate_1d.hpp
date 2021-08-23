#ifndef INTERPOLATE_1D_H
#define INTERPOLATE_1D_H

#include <valarray>

template <typename T, typename Function>
std::valarray<T> interpolate(const std::valarray<T>& x, Function v) {
    std::valarray<T> vh(x.size());
    
    for (size_t i =0; i<x.size(); i++){
        vh[i] = v(x[i]);
    }
    
    return vh;
}

#endif
