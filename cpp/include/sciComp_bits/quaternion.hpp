#ifndef QUATERNION_H
#define QUATERNION_H

#include <complex>
#include <iostream>

template <typename T>
class quaternion {

protected:
    
    std::complex<T> zc, wc;
    
    
public:
    quaternion(const T& a=0, const T& b=0, const T& c=0, const T& d=0);
    quaternion(const std::complex<T>& z, const std::complex<T>& w = std::complex<T>());
    quaternion(const quaternion<T>& h);
    quaternion<T>& operator=(const quaternion<T>& h);
    
    std::complex<T>& z();
    std::complex<T>& w();
    const std::complex<T>& z() const;
    const std::complex<T>& w() const;
};

template<typename T>
quaternion<T>::quaternion(const T& a, const T& b, const T& c, const T& d)
: zc(a,b), wc(c,d){
    
}

template<typename T>
quaternion<T>::quaternion(const std::complex<T>& z, const std::complex<T>& w)
: zc(z), wc(w){
    
}

template<typename T>
quaternion<T>::quaternion(const quaternion<T>& h)
:zc(h.zc), wc(h.wc){
    
}

template<typename T>
quaternion<T>& quaternion<T>::operator=(const quaternion<T>& h){
    
    if (this != &h){
        zc = h.zc;
        wc = h.wc;
    }
    
    return *this;
}

template<typename T>
std::complex<T>& quaternion<T>::z(){ return zc; }

template<typename T>
std::complex<T>& quaternion<T>::w(){ return wc; }

template<typename T>
const std::complex<T>& quaternion<T>::z() const { return zc; }

template<typename T>
const std::complex<T>& quaternion<T>::w() const { return wc; }

template<typename T>
quaternion<T> operator+(const quaternion<T>& h, quaternion<T>& m){
    
    quaternion<T> r;
    
    r.z() = h.z() + m.z();
    r.w() = h.w() + m.w();
    
    return r;
}

template<typename T>
quaternion<T> operator-(const quaternion<T>& h, const quaternion<T>& m){
    
    quaternion<T> r;
    
    r.z() = h.z() - m.z();
    r.w() = h.w() - m.w();
    
    return r;
}

template<typename T>
quaternion<T> conj(const quaternion<T>& h){
    
    quaternion<T> r;
    
    r.z() = conj(h.z());
    r.w() = -h.w();
    
    return r;
}

template<typename T>
quaternion<T> operator*(const quaternion<T>& h, const quaternion<T>& m){
    
    quaternion<T> r;
    
    r.z() = h.z()*m.z() - h.w()*conj(m.w());
    r.w() = h.z()*m.w() + h.w()*conj(m.z());
    
    return r;
}

template<typename T>
T norm(const quaternion<T>& h){
    return norm(h.z())+norm(h.w());
}

template<typename T>
T abs(const quaternion<T>& h){
    return sqrt(norm(h));
}

template<typename T>
quaternion<T> operator/ (const quaternion<T>& h, const quaternion<T>& m){
    
    quaternion<T> r = h*conj(m);
    T deno = abs(m.z())*abs(m.z())+abs(m.w())*abs(m.w());
    r.z() /= deno;
    r.w() /= deno;
    
    return r;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const quaternion<T>& h){
    
    out<<"("<<h.z()<<","<<h.w()<<")";
    return out;
}

template<typename T>
std::istream& operator>>(std::istream& is, quaternion<T>& h){
    
    std::complex<T> z, w;
    char c{};
    is >> c;
    
    if (c == '('){
        is >> z>>c;
        if (c == ','){
            is >> w>>c;
            if (c == ')') h = quaternion<T>(z,w);
            else is.setstate(std::ios_base::failbit);
        }
        else{
            if (c == ')') h = z;
            else is.setstate(std::ios_base::failbit);
        }
    }
    else{
        is.putback(c);
        is >> z;
        h = z;
    }
    
    return is;
}

#endif
