#include<iostream>

#include<comET.hpp>


#ifndef LONG
    #define LONG
#endif

#ifndef LD
    #define LD LONG double
#endif


// #define TestAdd
// #define TestSub
// #define TestMult
// #define TestDiv
// #define TestNeg
// #define TestConj
// #define TestAbs
// #define TestArg
// #define TestLog
// #define TestExp
// #define TestPow


#define Chaos



int main(){

    comET::complex<LD> zero;
    comET::complex<LD> real(3);//you can skip the template argument if you initialize it like this
    comET::complex<LD> complex(3,2);//you can skip the template argument if you initialize it like this

    std::cout<<"--Complexes--\n";
    std::cout<<zero<<std::endl;
    std::cout<<real<<std::endl;
    std::cout<<complex<<std::endl;

    #ifdef TestAdd    
    std::cout<<"--Addition--\n";
    std::cout<<complex+complex<<std::endl;
    std::cout<<1+complex<<std::endl;
    std::cout<<complex+1<<std::endl;
    #endif

    #ifdef TestSub    
    std::cout<<"--Subtraction--\n";
    std::cout<<complex-complex<<std::endl;
    std::cout<<1.3-complex<<std::endl;
    std::cout<<complex-1.3<<std::endl;
    #endif

    #ifdef TestMult    
    std::cout<<"--Multiplication--\n";
    std::cout<<complex*complex<<std::endl;
    std::cout<<3*complex<<std::endl;
    std::cout<<complex*3<<std::endl;
    #endif

    #ifdef TestDiv
    std::cout<<"--Division--\n";
    std::cout<<complex/complex<<std::endl;
    std::cout<<3/complex<<std::endl;
    std::cout<<comET::complex(3)/complex<<std::endl;
    std::cout<<complex/3<<std::endl;
    std::cout<<complex/comET::complex(3)<<std::endl;
    #endif


    #ifdef TestNeg    
    std::cout<<"--Negation--\n";
    std::cout<<-complex<<std::endl;
    std::cout<<-(complex+complex)<<std::endl;
    #endif


    #ifdef TestConj   
    std::cout<<"--Conjugation--\n";
    std::cout<<comET::conjugate(complex)<<std::endl;
    std::cout<<comET::conjugate(complex+complex)<<std::endl;
    std::cout<<comET::conjugate(comET::conjugate(complex+complex))<<std::endl;
    std::cout<<comET::conjugate(2)<<std::endl;
    #endif
    
    #ifdef TestAbs   
    std::cout<<"--Absolute value--\n";
    std::cout<<comET::abs(complex)<<std::endl;
    std::cout<<comET::abs(complex+complex)<<std::endl;
    std::cout<<comET::abs(3.2)<<std::endl;
    #endif
    

    
    #ifdef TestArg   
    std::cout<<"--Argument--\n";
    std::cout<<comET::arg(complex)<<std::endl;//this should be zero
    std::cout<<comET::arg(-1.)<<std::endl;//be careful! When you give integers, expect integers
    std::cout<<comET::arg(comET::arg(complex))<<std::endl;//this should be zero
    #endif
    
    #ifdef TestLog
    std::cout<<"--Log--\n";
    std::cout<<comET::log(complex)<<std::endl;
    std::cout<<comET::log(2.)<<std::endl;
    std::cout<<comET::log(-2.)<<std::endl;
    #endif
    

    #ifdef TestExp
    std::cout<<"--Exp--\n";
    std::cout<<comET::exp(complex)<<std::endl;
    std::cout<<comET::exp(2.)<<std::endl;
    std::cout<<comET::exp(-2.)<<std::endl;
    #endif
    

    #ifdef TestPow
    std::cout<<"--Pow--\n";
    std::cout<<comET::pow(complex,complex)<<std::endl;
    std::cout<<comET::pow(complex,2.)<<std::endl;
    std::cout<<comET::pow(2.,complex)<<std::endl;
    std::cout<<comET::pow(2.,2.)<<std::endl;
    #endif
    
    #ifdef Chaos
    std::cout<<"--Complicated Expression--\n";
    std::cout<<comET::log(comET::pow(3.*complex+comET::log(complex*3+comET::exp(complex-2)),-complex))<<std::endl;
    std::cout<<comET::log(comET::pow(complex,-complex))<<std::endl;
    #endif
    

    

    return 0;
}