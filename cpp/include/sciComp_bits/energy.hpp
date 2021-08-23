#ifndef ENERGY_H
#define ENERGY_H

template<typename T>
void energy(const std::valarray<T>& x, std::valarray<T>& D, std::valarray<T>& L){
    
    for (size_t i = 0; i<x.size()-2; i++){
        D[i] = 1/(x[i+1]-x[i]) + 1/(x[i+2]-x[i+1]);
    }
    
    for (size_t i = 0; i<x.size()-3; i++){
        L[i] = -1/(x[i+2] - x[i+1]);
    }
    
    L[x.size()-3] = 0;
    
}


#endif
