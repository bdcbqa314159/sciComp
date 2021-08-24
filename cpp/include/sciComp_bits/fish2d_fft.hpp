#ifndef FISH2D_FFT_H
#define FISH2D_FFT_H

#include "./fft_sin.hpp"
#include "./tridiag_ldlt.hpp"
#include "./row_col.hpp"

template <typename T>
std::valarray<T> fish2d_fft(size_t m, const std::valarray<T>& b) {
    std::valarray<T> tilde_b(b.size()), tilde_u(b.size()), u(b.size());
    
    col_type col(m-1);
    
    for(size_t j = 0; j<m-1; j++){
        std::valarray<T> bj = b[col(j)];
        tilde_b[col(j)] = (2./m)*fft_sin(bj);
    }
    
    row_type row(m-1);
    const T pi = acos(T(-1));
    
    for (size_t k = 0; k<m-1; k++){
        tridiag<T> poisson_1d(m-1, 4-2*cos((k+1)*pi/m), -1);
        tridiag_ldlt<T> factorized_1d(poisson_1d);
        tilde_u[row(k)] = factorized_1d.solve(tilde_b[row(k)]);
    }
    
    for (size_t j = 0; j<m-1; j++){
        std::valarray<T> tilde_uj = tilde_u[col(j)];
        u[col(j)] = fft_sin(tilde_uj);
    }
    
    return u;
}


#endif
