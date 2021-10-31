#ifndef ConjOp_head
#define ConjOp_head
#include<cmath>

#include<complex.hpp>
#include<UnaryOP.hpp>

namespace comET{

/*------------------------Conjugation---------------------------------*/
template<typename Expression, typename dummy=void>
class Conjugation: public UnaryOperator<Expression>{
    public:

    Conjugation(const Expression &Expr):UnaryOperator<Expression>(Expr){}

    inline auto Re() const {return this->Expr.Re() ;}
    inline auto Im() const {return -this->Expr.Im() ;}


    inline complex<typename Expression::numType> evaluate()const
    {return complex<typename Expression::numType>(this->Expr.Re(), - this->Expr.Im());}

};

template<typename Expression>
inline auto conjugate(const Expression &Expr){return Conjugation<Expression>(Expr);}


/*------------------------Conjugation of number---------------------------------*/
template<typename numType>
class Conjugation<numType, typename enable_if<std::is_arithmetic<numType>::value,void>::type>{
    public:
    numType value;
    Conjugation(const numType &value):value(value){}

    inline auto Re() const {return this->value;}
    inline auto Im() const {return 0 ;}


    inline complex<numType> evaluate()const{return complex<numType>(this->value, 0 );}
    friend std::ostream& operator<<(std::ostream& os, const Conjugation &expr)
    {os<<expr.evaluate();return os;} 

};




}





#endif