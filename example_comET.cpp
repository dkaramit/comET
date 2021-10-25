#include<iostream>

#include<comET.hpp>


#ifndef LONG
    #define LONG
#endif

#ifndef LD
    #define LD LONG double
#endif

int main(){

    comET::complex<LD> zero;
    comET::complex<LD> real(3);
    comET::complex<LD> complex(3,2);

    std::cout<<zero<<std::endl;
    std::cout<<real<<std::endl;
    std::cout<<complex<<std::endl;


    
    std::cout<<complex+complex<<std::endl;
    std::cout<<1+complex<<std::endl;
    std::cout<<complex+1<<std::endl;


    std::cout<<complex*complex<<std::endl;
    std::cout<<3*complex<<std::endl;
    std::cout<<complex*3<<std::endl;


    return 0;
}