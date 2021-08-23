#include <sciComp>
#include <iostream>
#include <string>

int testingQuaternion(){
    
    quaternion<double> h1 (1,1,7,9), h2(1,-1,-7,-9);
    
    std::cout<<"h1 = "<< h1<<std::endl;
    std::cout<<"h2 = "<< h2<<std::endl;
    std::cout<<"h1+h2 = "<< h1+h2<<std::endl;
    std::cout<<"h1-h2 = "<< h1-h2<<std::endl;
    std::cout<<"h1*h2 = "<< h1*h2<<std::endl;
    std::cout<<"h1/h2 = "<< h1/h2<<std::endl;
    
    std::cout<<"(h1/h2)*h2 = "<< (h1/h2)*h2<<std::endl;
    
    std::cout<<"enter a quaternion?"<<std::endl;
    std::cout<<">>>"<<std::endl;
    quaternion<double> q;
    std::cin>>q;
    
    std::cout<<"out "<<q<<std::endl;
    
    return 0;
}


int main() {
    
    testingQuaternion();
    
    return 0;
}
