#ifndef ConjOp_head
#define ConjOp_head
#include<cmath>

#include<complex.hpp>

namespace comET{

/*------------------------Conjugation---------------------------------*/
template<typename Expression>
class Conjugation{
    public:

    using numType = typename Expression::numType;
    
    Expression Expr;
    Conjugation(const Expression &Expr):Expr(Expr){}

    inline auto Re() const {return this->Expr.Re() ;}
    inline auto Im() const {return -this->Expr.Im() ;}


    inline complex<typename Expression::numType> evaluate()const
    {return complex<typename Expression::numType>(this->Expr.Re(), - this->Expr.Im());}

    friend std::ostream& operator<<(std::ostream& os, const Conjugation &Expr)
    {os<<Expr.evaluate();return os;} 


};

template<typename Expression>
inline auto Conjugate(const Expression &Expr){return Conjugation<Expression>(Expr);}

}

#endif