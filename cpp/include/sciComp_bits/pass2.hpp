#ifndef PASS2_H
#define PASS2_H

#include <valarray>
#include "./coeff.hpp"
#include "./matrix.hpp"
#include "./mesh.hpp"

template<typename T, size_t D>
void pass2(const mesh<T,D>& Th, const std::valarray<size_t>& num, matrix<T>&a){
    
    for (size_t e = 0; e<Th.size(); e++){
        T c = 1/meas(Th,e);
        for (size_t ie = 0; ie<D+1; ie++){
            size_t i = Th[e][ie];
            if (Th.is_boundary(i)) continue;
            a.entry(num[i],num[i]) += c*coeff(Th, e, ie, ie);
            for (size_t je = 0; je < D+1; je ++){
                size_t j = Th[e][je];
                if (je == ie || Th.is_boundary(j)) continue;
                a.entry(num[i], num[j]) += coeff(Th, e, ie, je);
            }
        }
    }
}


#endif
