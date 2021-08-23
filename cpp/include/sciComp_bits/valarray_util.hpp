#ifndef VALARRAY_UTIL_H
#define VALARRAY_UTIL_H

#include <valarray>

template <typename Vec1, typename Vec2>
typename Vec1::value_type dot(const Vec1& x, const Vec2& y) {
    typename Vec1::value_type sum = 0;
    
    for (size_t i = 0; i< x.size(); i++)
        sum += x[i]*y[i];
    return sum;
}

template <typename Vec>
typename Vec::value_type norm(const Vec& x) {
    return sqrt(dot(x,x));
}




#endif

