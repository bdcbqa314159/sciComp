#ifndef INDEX_H
#define INDEX_H

struct index_type {
    index_type(size_t n1): n(n1){}
    size_t operator()(size_t i, size_t j) const{
        return j+i*n;
    }
    
protected:
    size_t n;
};

#endif
