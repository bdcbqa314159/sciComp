#ifndef ASSEMBLY_MASS_H
#define ASSEMBLY_MASS_H

//#include <valarray>
//#include "./mesh.hpp"
//#include "./meas.hpp"

template<typename T, size_t D>
void assembly_mass(const mesh<T,D>& Th, const std::valarray<size_t>& num, std::valarray<T>& M){
    M.resize(Th.n_internal_vertex());
    M = 0;
    for (size_t e = 0; e<Th.size(); e++){
        T c = meas(Th,e)/(D+1);
        for (size_t r = 0; r<D+1; r++){
            size_t i = Th[e][r];
            if (!Th.is_boundary(i)) M[num[i]] += c;
        }
    }
}



#endif
