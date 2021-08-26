#ifndef COEFF_H
#define COEFF_H

#include "./mesh.hpp"
#include "./meas.hpp"


template<typename T>
T coeff(const mesh<T,1>& Th, size_t e, size_t ie, size_t je){
    
    return (ie==je) ? 1 : -1;
}

template<typename T>
T coeff(const mesh<T,2>& Th, size_t e, size_t ie, size_t je){
    
    size_t ia1 = Th[e][ie], ia2 = Th[e][je], ib1 = Th[e][(ie+1)%3], ib2 = Th[e][(je+1)%3], ic1 = Th[e][(ie+2)%3], ic2 = Th[e][(je+2)%3];
    const point<T,2>& a1 = Th.vertex(ia1), a2 = Th.vertex(ia2), b1 = Th.vertex(ib1), b2 = Th.vertex(ib2), c1 = Th.vertex(ic1), c2 = Th.vertex(ic2);
    
    return ((c1[0] - b1[0])*(c2[0]-b2[0]) + (c1[1]-b1[1])*(c2[1]-b2[1]))/4;
    
}

template<typename T>
T coeff(const mesh<T,3>& Th, size_t e, size_t ie, size_t je){
    
    size_t ia1 = Th[e][ie], ia2 = Th[e][je], ib1 = Th[e][(ie+1)%4], ib2 = Th[e][(je+1)%4], ic1 = Th[e][(ie+2)%4], ic2 = Th[e][(je+2)%4], id1 = Th[e][(ie+3)%4], id2 = Th[e][(je+3)%4];
    const point<T,3>& a1 = Th.vertex(ia1), a2 = Th.vertex(ia2), b1 = Th.vertex(ib1), b2 = Th.vertex(ib2), c1 = Th.vertex(ic1), c2 = Th.vertex(ic2), d1 = Th.vertex(id1), d2 = Th.vertex(id2);
    
    point<T,3> g1 = wedge(b1-a1, d1-c1) + wedge(d1-a1,c1-a1), g2 = wedge(b2-a2, d2-c2)+wedge(d2-a2, c2-a2);
    
    T sgn = (((ie-je)%2) == 0) ? 1 : -1;
    
    return sgn*dot(g1,g2)/36;
    
}


#endif
