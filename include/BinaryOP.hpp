#ifndef BinOp_head
#define BinOp_head
#include<iostream>
#include<cmath>

#include<complex.hpp>
#include<misc.hpp>

namespace comET{

template<typename leftHand, typename rightHand>
class BinaryOperator{
    protected:
    leftHand LH;
    rightHand RH;

    public:
    
    using numType = typename largestType<leftHand,rightHand>::numType;
    
    BinaryOperator(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}
    virtual complex<numType> evaluate() const=0;

    friend std::ostream& operator<<(std::ostream& os, const BinaryOperator &expr)
    {os<<expr.evaluate();return os;} 
};





}

#endif