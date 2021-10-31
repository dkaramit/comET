#ifndef LogOp_head
#define LogOp_head
#include<cmath>

#include<complex.hpp>
#include<UnaryOP.hpp>

namespace comET{

/*------------------------Log---------------------------------*/
template<typename Expression, typename dummy=void>
class Log: public UnaryOperator<Expression>{
    public:
    Log(const Expression &Expr):UnaryOperator<Expression>(Expr){}

    inline auto Re() const {return std::log(abs(this->Expr).Re())  ;}
    inline auto Im() const {return arg(this->Expr).Re() ;}


    inline complex<typename UnaryOperator<Expression>::numType> evaluate()const
    {return (std::log(abs(this->Expr).Re()) + complex<typename UnaryOperator<Expression>::numType>(0,1)*arg(this->Expr)).evaluate()  ;}
};

template<typename Expression>
inline auto log(const Expression &Expr){return Log<Expression>(Expr);}





/*------------------------Log of number---------------------------------*/
template<typename Expression>
class Log<Expression, typename enable_if<std::is_arithmetic<Expression>::value,void>::type>{
    public:
    using numType = Expression;
    

    Expression Expr;

    Log(const Expression &Expr):Expr(Expr){}

    inline auto Re() const {return std::log(std::abs(this->Expr));}
    inline auto Im() const {return std::atan2(0,this->Expr) ;}


    inline complex<Expression> evaluate()const
    {return (std::log(std::abs(this->Expr)) +  complex<Expression>(0,1)*std::atan2(0,this->Expr)).evaluate();}

    friend std::ostream& operator<<(std::ostream& os, const Log &Expr)
    {os<<Expr.evaluate();return os;} 

};


}

#endif