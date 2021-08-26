#ifndef PASS1_H
#define PASS1_H

#include <list>
#include <vector>
#include <valarray>
#include "./unique_insert.hpp"
#include "./matrix.hpp"
#include "./mesh.hpp"


template<typename T, size_t D>
void pass1(const mesh<T,D>& Th, const std::valarray<size_t>& num, matrix<T>& a){
    
    size_t n = Th.n_internal_vertex();
    std::vector<std::list<size_t>>s(n);
    
    for (size_t e = 0; e<Th.size(); e++){
        for (size_t ie = 0; ie < D+1; ie++){
            size_t i = Th[e][ie];
            if (Th.is_boundary(i)) continue;
            unique_insert(s[num[i]], num[i]);
            for (size_t je = 0; je < D+1; je++){
                size_t j = Th[e][je];
                if (je == ie || Th.is_boundary(j)) continue;
                unique_insert(s[num[i]], num[j]);
            }
        }
    }
    
    a.resize(s,n);
}



#endif
