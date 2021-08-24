#include <sciComp>
#include <iostream>
#include <string>
#include <complex>
#include <valarray>
#include <iomanip>
#include <cassert>
#include <algorithm>

std::complex<double> f_(double x) { return (x<0.5) ? x: 1-x; }
double u_(double x) { return (1-x*x)/2; }
double f_(const double& x, const double& y) { return 1;}

int testingQuaternion(){
    
    quaternion<double> h1 (1,1,7,9), h2(1,-1,-7,-9);
    
    std::cout<<"h1 = "<< h1<<std::endl;
    std::cout<<"h2 = "<< h2<<std::endl;
    std::cout<<"h1+h2 = "<< h1+h2<<std::endl;
    std::cout<<"h1-h2 = "<< h1-h2<<std::endl;
    std::cout<<"h1*h2 = "<< h1*h2<<std::endl;
    std::cout<<"h1/h2 = "<< h1/h2<<std::endl;
    
    std::cout<<"(h1/h2)*h2 = "<< (h1/h2)*h2<<std::endl;
    
//    std::cout<<"enter a quaternion?"<<std::endl;
//    std::cout<<">>>"<<std::endl;
//    quaternion<double> q;
//    std::cin>>q;
//
//    std::cout<<"out "<<q<<std::endl;
    
    return 0;
}

int testValArray(){
    
    std::valarray<int> x = { 10, 2, 20, 1, 30 };
    std::valarray<int> y = { 1,0,0,0,0 };
    
    std::cout<<dot(x,y)<<std::endl;
    std::cout<<norm(y)<<std::endl;
    
    return 0;
}

int testingFft(){
    
    size_t n = 32;
    std::valarray<std::complex<double>> x(n);
    
    for (size_t k = 0; k<n; k++){
        x[k] = f_(1.*k/n);
    }
    
    assert(fabs(log2(n) - int(log2(n))) < 1e-10);
    const double pi = acos(-1.0);
    const std::complex<double> i (0,1);
    std::complex<double> w = exp((2*pi/n)*i);
    
    std::valarray<std::complex<double>> y(n);
    
    fft(1./w, x, y);
    
    std::cout<<std::setprecision(16);
    
    for (size_t k = 0; k<n; k++){
        std::cout<<y[k]<<std::endl;
    }
    
    return 0;
}

int testingPoisson1D(){
    
    size_t n = 32;
    
    double h = 2./n;
    
    std::valarray<double> D(2, n-1), L(-1,n-2);
    inplace_factorize(D, L);
    std::valarray<double> b(h*h, n-1);
    inplace_solve(D,L,b);
    std::valarray<double> pi_h_u(n-1);
    
    for (size_t i = 0; i<n-1; i++){
        pi_h_u[i] = u_(-1+(1+i)*h);
    }
    
    std::valarray<double> uerr = abs(pi_h_u - b);
    std::cout<<"err = "<<uerr.max()<<std::endl;
    
    
    return 0;
}

int testingFiniteElements1D(){
    
    size_t n = 1000;
    double alpha = 0.5;
    double beta = 2/alpha;
    
    std::valarray<double> x(n+1);
    for (size_t i = 0; i<n+1; i++){
        x[i] = -1 + 2*chi(beta,1.0*i/n);
    }
    
    std::valarray<double>M(n-1);
    tridiag<double> A(n-1);
    mass (x,M);
    energy (x,A);
    
    tridiag_ldlt<double> C(A);
    
    std::valarray<double> pi_h_f = interpolate(x,f(alpha)), b = M*std::valarray<double>(pi_h_f[range(1,n)]), uh(0.0, n+1);
    
    uh[range(1,n)] = C.solve(b);
    std::valarray<double> pi_h_u = interpolate(x, u(alpha)), u_err = (pi_h_u - uh)[range(1,n)], uerr_linf =  abs(u_err);
    
    std::cerr<<"err_l2 "<<sqrt(dot(u_err, M*u_err))<<std::endl<<"err_linf "<<uerr_linf.max()<<std::endl<<"err_h1 "<<sqrt(dot(u_err, A*u_err))<<std::endl;
    
    
    
    return 0;
}

int testingPoisson2D(){
    
    size_t m = 64;
    
    double h = 2./m;
    
    index_type elt (m+1), num (m-1);
    
    std::valarray<double> pi_h_f = interpolate(m, f_), b((m-1)*(m-1));
    
    for (size_t i = 0; i<m-1; i++){
        for (size_t j = 0; j<m-1; j++){
            b[num(i,j)] = h*h*pi_h_f[elt(i+1, j+1)];
        }
    }
    
    std::valarray<double> uh(0., (m+1)*(m+1)), x = fish2d_fft(m,b);
    
    for (size_t i = 0; i<m-1; i++){
        for (size_t j = 0; j<m-1; j++){
            uh[elt(i+1, j+1)] = x[num(i,j)];
        }
    }
    
    return 0;
}




int main() {
    
//    testingQuaternion();
//    testValArray();
//    testingFft();
//    testingPoisson1D();
//    testingFiniteElements1D();
    testingPoisson2D();
    
    return 0;
}
