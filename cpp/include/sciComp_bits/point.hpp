#ifndef POINT_H
#define POINT_H

#include <array>
#include <cmath>

template<typename T, size_t D>
class point : public std::array<T,D>{};

template<typename T, size_t D>
std::ostream& operator<<(std::ostream& os, const point<T,D>& a){
    
    for (size_t i = 0; i< D; i++){
        os << a[i];
        if (i != D-1) os<<" ";
    }
    
    return os;
}

template<typename T, size_t D>
std::istream& operator>>(std::istream& is, point<T,D>& a){
    
    for (size_t i = 0; i< D; i++){
        is >> a[i];
    }
    
    return is;
}

template<typename T, size_t D>
point<T,D> operator+ (const point<T,D>& u, const point<T,D>& v){
    
    point<T,D> w;
    
    for (size_t i = 0; i<D; i++) w[i] = u[i]+v[i];
    
    return w;
    
}

template<typename T, size_t D>
point<T,D> operator- (const point<T,D>& u, const point<T,D>& v){
    
    point<T,D> w;
    
    for (size_t i = 0; i<D; i++) w[i] = u[i]-v[i];
    
    return w;
    
}

template<typename T, size_t D>
T dot(const point<T,D>& u, const point<T,D>& v){
    
    T sum = 0;
    for (size_t i = 0; i<D; i++){
        sum += u[i]*v[i];
    }
    
    return sum;
}

template<typename T, size_t D>
T dot(const point<T,D>& u){
    
    return std::sqrt(dot(u,u));
}

template<typename T, size_t D>
T dist(const point<T,D>& a, const point<T,D>& b){
    
    return norm(b-a);
}

template<typename T>
point<T,3> wedge(const point<T,3>& u, const point<T,3>& v){
    
    point<T,3> w;
    w[0] = u[1]*v[2] - u[2]*v[1];
    w[1] = u[2]*v[0] - u[0]*v[2];
    w[2] = u[0]*v[1] - u[1]*v[0];
    
    return w;
}

#endif
