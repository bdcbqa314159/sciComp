#ifndef ASSEMBLY_ENERGY_H
#define ASSEMBLY_ENERGY_H

#include <valarray>
#include "./pass1.hpp"
#include "./pass2.hpp"
#include "./matrix.hpp"
#include "./mesh.hpp"

template<typename T, size_t D>
void assembly_energy(const mesh<T,D>& Th, const std::valarray<size_t>& num, matrix<T>& a){
    
    pass1(Th, num, a);
    pass2(Th, num, a);
    
}

#endif
