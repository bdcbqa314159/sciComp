#ifndef MATRIX_H
#define MATRIX_H

#include <valarray>
#include <iostream>
#include <list>
#include <vector>
#include <cassert>

template <typename T>
class matrix {
protected:
    std::valarray<size_t> ptr;
    std::valarray<size_t> idx;
    std::valarray<T> val;
    size_t idxmax;
    
public:
    matrix();
    matrix(const matrix<T>& s);
    matrix<T>& operator= (const matrix<T>& s);
    void resize(const std::vector<std::list<size_t>>& s, size_t lncol);
    size_t nrow() const;
    size_t ncol() const;
    size_t nnz() const;
    
    void resize(size_t nrow, size_t ncol, size_t nnz);
    std::valarray<T> operator* (const std::valarray<T>&) const;
    const T& operator() (size_t i , size_t j) const;
    T& entry (size_t i, size_t j);
    template<typename U> friend std::istream& operator>> (std::istream& is, matrix<U>& s);
    template<typename U> friend std::ostream& operator<< (std::ostream& is, const matrix<U>& s);
};


template<typename T>
matrix<T>::matrix(): ptr(0), idx(0), val(0), idxmax(0){
    
}

template<typename T>
matrix<T>::matrix(const matrix<T>& a): ptr(a.ptr), idx(a.idx), val(a.val), idxmax(a.idxmax){
    
}

template<typename T>
matrix<T>& matrix<T>::operator= (const matrix<T>& a){
    
    if (this != &a){
        resize(a.nrow(), a.ncol(), a.nnz());
        ptr = a.ptr;
        idx = a.idx;
        val = a.val;
        idxmax = a.idxmax;
    }
    
    return *this;
}

template<typename T>
void matrix<T>::resize(size_t nr, size_t nc, size_t nnz){
    
    ptr.resize(nr+1);
    idx.resize(nnz);
    val.resize(nnz);
    idxmax = nc;
    
}

template<typename T>
size_t matrix<T>::nrow() const {return ptr.size() - 1;}

template<typename T>
size_t matrix<T>::ncol() const {return idxmax;}

template<typename T>
size_t matrix<T>::nnz() const {return idx.size();}

template<typename T>
std::valarray<T> matrix<T>::operator* (const std::valarray<T>& x) const{
    std::valarray<T> y(T(0), nrow());
    
    for (size_t i = 0; i<nrow(); i++){
        for (size_t p = ptr[i]; p<ptr[i]; p++){
            y[i] += val[p]*x[idx[p]];
        }
    }
    return y;
}

template<typename T>
const T& matrix<T>::operator() (size_t i, size_t j) const{
    for (size_t p = ptr[i]; p != ptr[i+1]; p++){
        if (idx[p] == j) return val[p];
    }
    return T(0);
}

template<typename T>
T& matrix<T>::entry(size_t i, size_t j){
    for (size_t p = ptr[i]; p != ptr[i+1]; p++){
        if (idx[p] == j) return val[p];
    }
    static T zero = 0;
    assert(0); return zero;
}

template<typename T>
std::ostream& operator<< (std::ostream& s, const matrix<T>& a){
    s<<"%%MatrixMarket matrix coordinate real general"<<std::endl<<a.nrow()<<" "<<a.ncol()<<" "<<a.nnz()<<std::endl;
    for(size_t i = 0; i<a.nrow(); i++){
        for(size_t p = a.ptr[i]; p<a.ptr[i+1]; p++){
            s<<i+1<<" "<<a.idx[p]+1<<" "<<a.val[p]<<std::endl;
        }
    }
    
    return s;
}

template<typename T>
std::istream& operator>>(std::istream& is, matrix<T>& a){
    
    is>>std::ws;
    char c = is.peek();
    if (c == '%') while (is.good() && (c != '\n')) is.get(c);
    size_t nrow, ncol, nnz;
    
    is >> nrow >> ncol >> nnz;
    
    a.resize(nrow, ncol, nnz);
    a.ptr = 0;
    
    for (size_t i_prec = 0, p=0; p<nnz; p++){
        size_t i;
        is >> i >> a.idx[p]>>a.val[p];
        i--;
        a.idx[p]--;
        assert (a.idx[p] < ncol);
        
        if (p == 0 || i != i_prec){
            assert(p==0 || i_prec <i);
            i_prec = i;
        }
        a.ptr[i+1]++;
    }
    
    for (size_t i =0; i<nrow; i++){
        a.ptr[i+1] += a.ptr[i];
    }
    
    return is;
}

template<typename T>
void matrix<T>::resize(const std::vector<std::list<size_t>>& s, size_t ncol){
    
    size_t nrow = s.size();
    ptr.resize(nrow + 1);
    ptr[0] = 0;
    
    for (size_t i = 0; i<nrow; i++) ptr[i+1] = ptr[i] + s[i].size();
    
    size_t nnz = ptr[s.size()];
    idx.resize(nnz);
    
    for (size_t i = 0, p =0; i<nrow; i++){
        for (std::list<size_t>::const_iterator iter = s[i].begin(), last = s[i].end(); iter != last; ++iter, ++p){
            idx[p] = *iter;
        }
    }
    
    val.resize(nnz);
    val = 0;
    idxmax = ncol;
    
}


#endif
