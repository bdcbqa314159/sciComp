#ifndef FFT_SIN_H
#define FFT_SIN_H

#include "./fft.hpp"
#include <valarray>
#include <complex>
#include <cassert>

template<typename T>
std::valarray<T> fft_sin(const std::valarray<T>& v){
    
    size_t m = v.size()+1;
    std::valarray<std::complex<T>> v_ext(2*m), hat_v(2*m);
    
    v_ext[0] = 0;
    
    for (size_t p = 1; p<m; p++){
        v_ext[p] = v[p-1];
        v_ext[2*m-p] = -v[p-1];
    }
    
    const T pi = acos(T(-1));
    std::complex<T> i(0,1), w = exp((pi/m)*i);
    assert(fabs(log2(m) - int(log2(m))) < 1e-10);
    fft(w,v_ext,hat_v);
    std::valarray<T> tilde_v(m-1);
    
    for (size_t p = 1; p<m; p++){
        tilde_v[p-1] = m*hat_v[p].imag();
    }
    
    return tilde_v;
}







#endif
