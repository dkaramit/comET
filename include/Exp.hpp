#ifndef ExpOp_head
#define ExpOp_head
#include<cmath>

#include<complex.hpp>
#include<UnaryOP.hpp>

namespace comET{

/*------------------------Exp---------------------------------*/
template<typename Expression, typename dummy=void>
class Exp: public UnaryOperator<Expression>{
    public:
    Exp(const Expression &Expr):UnaryOperator<Expression>(Expr){}

    inline auto Re() const {return std::exp(this->Expr.Re())*std::cos(this->Expr.Im())  ;}
    inline auto Im() const {return std::exp(this->Expr.Re())*std::sin(this->Expr.Im()) ;}


    inline complex<typename UnaryOperator<Expression>::numType> evaluate()const
    {return complex<typename UnaryOperator<Expression>::numType>(std::exp(this->Expr.Re())*std::cos(this->Expr.Im()), std::exp(this->Expr.Re())*std::sin(this->Expr.Im()));}
};

template<typename Expression>
inline auto exp(const Expression &Expr){return Exp<Expression>(Expr);}





/*------------------------Exp of number---------------------------------*/
template<typename Expression>
class Exp<Expression, typename enable_if<std::is_arithmetic<Expression>::value,void>::type>{
    public:
    using numType = Expression;
    

    Expression Expr;

    Exp(const Expression &Expr):Expr(Expr){}

    inline auto Re() const {return std::exp(this->Expr);}
    inline auto Im() const {return 0 ;}


    inline complex<Expression> evaluate()const
    {return complex<Expression>(std::exp(this->Expr));}

    friend std::ostream& operator<<(std::ostream& os, const Exp &Expr)
    {os<<Expr.evaluate();return os;} 

};


}

#endif