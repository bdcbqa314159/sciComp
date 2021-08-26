#ifndef DIRICHLET_H
#define DIRICHLET_H

#include "./mesh.hpp"
#include "./matrix.hpp"
#include "./renumbering.hpp"
#include "./assembly_mass.hpp"
#include "./assembly_energy.hpp"
#include "./interpolate.hpp"
#include "./valarray_util.hpp"
#include "./cg.hpp"
#include "./eye.hpp"

template<typename T, size_t D>
std::valarray<T> dirichlet(const mesh<T,D>& Th, const std::valarray<T>& fh){
    
    std::valarray<size_t> num;
    std::valarray<T> M;
    matrix<T> A;
    
    renumbering(Th, num);
    assembly_mass(Th, num, M);
    assembly_energy(Th, num, A);
    
    std::valarray<bool> internal(Th.n_vertex());
    
    for(size_t i = 0; i<Th.n_vertex(); i++){
        internal[i] = !Th.is_boundary(i);
    }
    
    std::valarray<T> b = M*fh[internal];
    std::valarray<T> x(0., b.size());
    cg(A, x, b, eye(), 100000, 1e-10);
    std::valarray<T> uh(0., Th.n_vertex());
    uh[internal] = x;
    return uh;
}

#endif
