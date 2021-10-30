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
// #define TestArg
// #define TestNeg
// #define TestConj
// #define TestAbs
#define TestArg





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
    std::cout<<comET::Conjugate(complex)<<std::endl;
    std::cout<<comET::Conjugate(complex+complex)<<std::endl;
    std::cout<<comET::Conjugate(comET::Conjugate(complex+complex))<<std::endl;
    #endif
    
    #ifdef TestAbs   
    std::cout<<"--Absolute value--\n";
    std::cout<<comET::Abs(complex)<<std::endl;
    std::cout<<comET::Abs(complex+complex)<<std::endl;
    std::cout<<comET::Abs(3.2)<<std::endl;
    #endif
    

    
    #ifdef TestArg   
    std::cout<<"--Argument--\n";
    std::cout<<comET::Arg(complex)<<std::endl;//this should be zero
    std::cout<<comET::Arg(-1.)<<std::endl;//be careful! When you give integers, expect integers
    std::cout<<comET::Arg(comET::Arg(complex))<<std::endl;//this should be zero
    #endif
    

    

    return 0;
}