#ifndef INTERPOLATE_H
#define INTERPOLATE_H
#include <valarray>
#include "./mesh.hpp"

template<typename T, size_t D>
std::valarray<T>
interpolate(const mesh<T,D>& Th, T(*v)(const point<T,D>& p)){
    
    std::valarray<T> vh(Th.n_vertex());
    for(size_t i = 0; i<Th.n_vertex(); i++){
        vh[i] = v(Th.vertex(i));
    }
    
    return vh;
    
}



#endif
