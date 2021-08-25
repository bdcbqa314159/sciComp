#ifndef ELEMENT_H
#define ELEMENT_H

#include <valarray>
#include <iostream>

template<size_t D>
class element : public std::array<size_t, D+1>{};

template<size_t D>
std::ostream& operator<<(std::ostream& os, const element<D>& K){
    
    for (size_t i = 0; i< D+1; i++){
        os << K[i+1]<< " ";
    }
    
    return os;
}

template<size_t D>
std::istream& operator>>(std::istream& is, element<D>& K){
    
    for (size_t i = 0; i< D+1; i++){
        is >> K[i]; K[i]--;
    }
    
    return is;
}

#endif
