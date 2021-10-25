#ifndef complex_head
#define complex_head

#include<iostream>

namespace comET{

// this is the complex number class.
template<typename LD, typename dummy=void>
class complex{
    LD real;
    LD imaginary;

    public:

    //this will be used to propagate LD without needeless template arguments
    using numType = LD;

    complex():real(0),imaginary(0){}
    complex(const LD &real):real(real),imaginary(0){}
    complex(const LD &real, const LD &imaginary):real(real),imaginary(imaginary){}

    LD Re()const{return real;}
    LD Im()const{return imaginary;}

    LD& Re(){return real;}
    LD& Im(){return imaginary;}

    complex evaluate(){return complex(real,imaginary);}

    friend std::ostream& operator<<(std::ostream& os, const complex &z){os<<"("<<z.Re()<<","<<z.Im()<<")"; return os;} 

};

};

#endif