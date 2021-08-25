#ifndef CG_H
#define CG_H

#include <iostream>
#include "./valarray_util.hpp"
#include "./tridiag_ldlt.hpp"

template<typename Mat, typename Vec, typename Precond, typename Real>
int cg(const Mat& A, Vec& x, const Vec& b, const Precond& M, int maxiter, Real tol){
    
    Real nb = norm(b);
    
    if (nb == 0){
        x = 0;
        return 0;
    }
    
    Vec r = b - A*x;
    Vec z = M.solve(r);
    Vec p = z;
    Real rho = dot(r,z);
    Real rho_prev = rho;
    
    std::clog<<"pcg: 0 "<<norm(r)/nb<<std::endl;
    
    for (int i = 1; i< maxiter; i++){
        Vec q = A*p;
        Real alpha = rho/dot(p,q);
        x += alpha*p;
        r -= alpha*q;
        Real nr = norm(r)/nb;
        
        std::clog<<"pcg: "<<i<<" "<<nr<<std::endl;
        if (nr <= tol) return 0;
        
        z = M.solve(r);
        rho = dot(r,z);
        Real beta = rho/rho_prev;
        rho_prev = rho;
        p = z + beta*p;
    }
    
    return 1;
}



#endif
