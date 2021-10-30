#ifndef NegOp_head
#define NegOp_head
#include<cmath>

#include<complex.hpp>

namespace comET{

/*------------------------Negation---------------------------------*/
template<typename Expression>
class Negation{
    public:

    using numType = typename Expression::numType;
    Expression Expr;
    Negation(const Expression &Expr):Expr(Expr){}

    inline auto Re() const {return -this->Expr.Re() ;}
    inline auto Im() const {return -this->Expr.Im() ;}


    inline complex<numType> evaluate()const
    {return complex<numType>(-this->Expr.Re(), - this->Expr.Im());}

    friend std::ostream& operator<<(std::ostream& os, const Negation &Expr)
    {os<<Expr.evaluate();return os;} 

};

template<typename Expression>
inline auto operator-(const Expression &Expr){return Negation<Expression>(Expr);}

}

#endif