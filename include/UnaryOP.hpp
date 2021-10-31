#ifndef UnOp_head
#define UnOp_head
#include<iostream>
#include<cmath>

#include<complex.hpp>
#include<misc.hpp>

namespace comET{

template<typename Expression>
class UnaryOperator{
    protected:
    Expression Expr;

    public:
    
    using numType = typename Expression::numType;
    
    UnaryOperator(const Expression &Expr):Expr(Expr){}
    virtual complex<numType> evaluate() const=0;

    friend std::ostream& operator<<(std::ostream& os, const UnaryOperator &expr)
    {os<<expr.evaluate();return os;} 
};





}

#endif