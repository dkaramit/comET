#ifndef NegOp_head
#define NegOp_head
#include<cmath>

#include<complex.hpp>
#include<UnaryOP.hpp>

namespace comET{

/*------------------------Negation---------------------------------*/
template<typename Expression>
class Negation: public UnaryOperator<Expression>{
    public:
    Negation(const Expression &Expr):UnaryOperator<Expression>(Expr){}

    inline auto Re() const {return -this->Expr.Re() ;}
    inline auto Im() const {return -this->Expr.Im() ;}


    inline complex<typename UnaryOperator<Expression>::numType> evaluate()const
    {return complex<typename UnaryOperator<Expression>::numType>(-this->Expr.Re(), - this->Expr.Im());}

};

template<typename Expression>
inline auto operator-(const Expression &Expr){return Negation<Expression>(Expr);}

}

#endif