#ifndef ROW_COL_H
#define ROW_COL_H

#include <valarray>

struct row_type {
    row_type(size_t n1): n(n1){}
    std::slice operator()(size_t j) const{
        return std::slice(n*j, n, 1);
    }
    
protected:
    size_t n;
};

struct col_type {
    col_type(size_t n1): n(n1){}
    std::slice operator() (size_t i) const{
        return std::slice(i,n,n);
    }
    
protected:
    size_t n;
};


#endif
