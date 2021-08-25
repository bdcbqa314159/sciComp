#ifndef MEAS_H
#define MEAS_H

#include "./mesh.hpp"

template <typename T>
T meas(const mesh<T,1>& Th, size_t e) {
    const element<1>& K = Th[e];
    size_t ia = K[0], ib = K[1];
    const point<T,1>& a = Th.vertex(ia), b = Th.vertex(ib);
    return b[0] -a[0];
}

template <typename T>
T meas(const mesh<T,2>& Th, size_t e) {
    const element<2>& K = Th[e];
    size_t ia = K[0], ib = K[1], ic = K[2];
    const point<T,2>& a = Th.vertex(ia), b = Th.vertex(ib), c = Th.vertex(ic);
    return ((b[0] -a[0])*(c[1] - a[1]) - (b[1]-a[1])*(c[0]-a[0]))/2;
}

template <typename T>
T meas(const mesh<T,3>& Th, size_t e) {
    const element<3>& K = Th[e];
    size_t ia = K[0], ib = K[1], ic = K[2], id = K[3];
    const point<T,3>& a = Th.vertex(ia), b = Th.vertex(ib), c = Th.vertex(ic), d = Th.vertex(id);
    return dot(b-a, wedge(c-a, d-a))/6;
}


#endif
