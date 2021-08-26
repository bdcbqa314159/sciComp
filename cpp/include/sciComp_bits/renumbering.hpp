#ifndef RENUMBERING_H
#define RENUMBERING_H
#include <valarray>
#include "./mesh.hpp"

template <typename T, size_t D>
void renumbering(const mesh<T,D>& Th, std::valarray<size_t>& num){
    
    num.resize(Th.n_vertex());
    size_t i_bdr = 0, i_int = 0;
    for (size_t i = 0; i<Th.n_vertex(); i++){
        if (Th.is_boundary(i))
            num[i] =  i_bdr++;
        else num[i] = i_int++;
    }
}




#endif
