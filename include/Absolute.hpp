#ifndef AbsOp_head
#define AbsOp_head
#include<cmath>

#include<complex.hpp>
#include<UnaryOP.hpp>

namespace comET{

/*------------------------Absolute---------------------------------*/
template<typename Expression, typename dummy=void>
class Absolute: public UnaryOperator<Expression>{
    public:
    Absolute(const Expression &Expr):UnaryOperator<Expression>(Expr){}

    inline auto Re() const {return std::sqrt(this->Expr.Re()*this->Expr.Re() + this->Expr.Im()*this->Expr.Im());}
    inline auto Im() const {return 0 ;}


    inline complex<typename UnaryOperator<Expression>::numType> evaluate()const
    {return complex<typename UnaryOperator<Expression>::numType>(std::sqrt(this->Expr.Re()*this->Expr.Re() + this->Expr.Im()*this->Expr.Im()), 0 );}
};

template<typename Expression>
inline auto abs(const Expression &Expr){return Absolute<Expression>(Expr);}





/*------------------------Absolute of number---------------------------------*/
template<typename Expression>
class Absolute<Expression, typename enable_if<std::is_arithmetic<Expression>::value,void>::type>{
    public:
    using numType = Expression;
    

    Expression Expr;

    Absolute(const Expression &Expr):Expr(Expr){}

    inline auto Re() const {return std::abs(this->Expr);}
    inline auto Im() const {return 0 ;}


    inline complex<Expression> evaluate()const
    {return complex<Expression>(std::abs(this->Expr), 0 );}

    friend std::ostream& operator<<(std::ostream& os, const Absolute &Expr)
    {os<<Expr.evaluate();return os;} 

};


}

#endif