#ifndef INTERPOLATE_2D_H
#define INTERPOLATE_2D_H

#include <valarray>

template <typename T>
std::valarray<T> interpolate(size_t n, T (*v)(const T&, const T&)) {
    
    std::valarray<T> pi_h_v ((n+1)*(n+1));
    T h = 2./n;
    
    for (size_t j = 0; j<n+1; j++){
        for (size_t i = 0; i<n+1; i++){
            pi_h_v[i+j*(n+1)] = v(-1+i*h, -1+j*h);
        }
    }
    return pi_h_v;
}

#endif
