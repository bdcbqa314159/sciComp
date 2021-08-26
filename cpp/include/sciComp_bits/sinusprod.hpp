#ifndef SINUSPROD_H
#define SINUSPROD_H

const double pi = acos(double(-1));

template<size_t D>
double u1(const point<double, D>& x){
    
    double value = 1;
    
    for (size_t i = 0; i<D; i++){
        value *= sin(pi*x[i]);
    }
    
    return value;
}

template<size_t D>
double f1(const point<double , D>& x){
    return D*pi*pi*u1(x);
}

#endif
