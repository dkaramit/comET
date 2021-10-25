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

    Variable():real(0),imaginary(0){}
    Variable(const LD &real):real(real),imaginary(0){}
    Variable(const LD &real, const LD &imaginary):real(real),imaginary(imaginary){}

    LD Re()const{return real;}
    LD Im()const{return imaginary;}

    LD& Re(){return real;}
    LD& Im(){return imaginary;}

    friend std::ostream& operator<<(std::ostream& os, const Variable &expr){os<<expr.evaluate();return os;} 

};

};

#endif