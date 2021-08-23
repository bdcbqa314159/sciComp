#include <sciComp>
#include <iostream>
#include <string>
#include <complex>
#include <valarray>
#include <iomanip>
#include <cassert>

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

std::complex<double> f(double x) {return (x<0.5) ? x: 1-x;}

int testingFft(){
    
    size_t n = 32;
    std::valarray<std::complex<double>> x(n);
    
    for (size_t k = 0; k<n; k++){
        x[k] = f(1.*k/n);
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


int main() {
    
//    testingQuaternion();
//    testValArray();
    testingFft();
    
    return 0;
}
