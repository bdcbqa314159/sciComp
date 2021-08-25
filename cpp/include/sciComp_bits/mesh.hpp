#ifndef MESH_H
#define MESH_H

#include "./point.hpp"
#include "./element.hpp"
#include <vector>

template <typename T, size_t D>
class mesh: std::vector<element<D>> {
    
public:
    mesh();
    mesh(const mesh<T,D>& s);
    mesh<T,D>& operator= (const mesh<T,D>& s);
    
    size_t n_vertex() const;
    size_t n_interval_vertex() const;
    bool is_boundary(size_t i) const;
    point<T,D>& vertex(size_t i);
    const point<T,D>& vertex(size_t i) const;
    template<typename U, size_t D1> friend std::istream& operator>>(std::istream& is, mesh<U,D1>& s);
    template<typename U, size_t D1> friend std::ostream& operator<<(std::ostream& os, const mesh<U,D1>& s);
    
protected:
    std::vector<point<T,D>> x;
    std::vector<size_t> b;
    size_t ni;
};

template <typename T, size_t D>
mesh<T,D>::mesh()
: std::vector<element<D>>(), x(), b(), ni(0){
    
}

template <typename T, size_t D>
mesh<T,D>::mesh(const mesh<T,D>& m)
: std::vector<element<D>>(m), x(m.x), b(m.b), ni(m.ni){
    
}

template <typename T, size_t D>
mesh<T,D>& mesh<T,D>::operator=(const mesh<T,D>& m){
    
    if (this != &m){
        std::vector<element<D>>::operator=(m);
        x = m.x;
        b = m.b;
        ni = m.ni;
    }
    
    return *this;
    
}

template <typename T, size_t D>
size_t mesh<T,D>::n_vertex() const {return x.size();}

template <typename T, size_t D>
size_t mesh<T,D>::n_interval_vertex() const {return ni;}

template <typename T, size_t D>
bool mesh<T,D>::is_boundary(size_t i) const {return b[i] != 0;}

template <typename T, size_t D>
point<T,D>& mesh<T,D>::vertex(size_t i) {return x[i];}

template <typename T, size_t D>
const point<T,D>& mesh<T,D>::vertex(size_t i) const {return x[i];}

template <typename T, size_t D>
std::ostream& operator<<(std::ostream& os, const mesh<T,D>& m){
    
    os<<m.x.size()<<std::endl;
    for (size_t i = 0, n = m.x.size(); i<n; i++){
        os << m.x[i] << " "<<m.b[i]<<std::endl;
    }
    
    os << m.size() << std::endl;
    
    for (size_t e = 0; e<m.size(); e++){
        os << m[e]<<" 1"<<std::endl;
    }
    return os;
}

template <typename T, size_t D>
std::istream& operator>>(std::istream& is, mesh<T,D>& m){
    
    size_t nx;
    m.x.resize(nx);
    m.b.resize(nx);
    m.ni = 0;

    for(size_t i = 0; i<nx; i++){
        is >> m.x[i] >> m.b[i];
        if (m.b[i] == 0) m.ni++;
    }
    
    size_t ne, domain;
    is >> ne;
    m.resize(ne);
    
    for (size_t e = 0; e<ne; e++){
        is >> m[e] >> domain;
    }
    
    return is;
}

#endif
