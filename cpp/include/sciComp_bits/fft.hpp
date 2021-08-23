#ifndef FFT_H
#define FFT_H

#include <valarray>
template<typename T>
void fft(const T& w, const std::valarray<T>& f, std::valarray<T>& F){
    
    size_t n = f.size();
    if (n==0) return;
    else if (n==1) {F[0] = f[0]; return;}
    
    size_t m = n/2;
    
    std::valarray<T> f0(m), f1(m), F0(m), F1(m);
    
    for (size_t k = 0; k<m; k++){
        f0[k] = f[2*k];
        f1[k] = f[2*k+1];
    }
    
    fft(w*w, f0, F0);
    fft(w*w, f1, F1);
    
    T wk = 1;
    
    for (size_t k = 0; k<m; k++){
        F[k] = 0.5*(F0[k] + wk*F1[k]);
        F[m+k] = 0.5*(F0[k] - wk*F1[k]);
        wk = w*wk;
    }
}

#endif
