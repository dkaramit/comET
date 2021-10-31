#ifndef ArgOp_head
#define ArgOp_head
#include<cmath>

#include<complex.hpp>
#include<UnaryOP.hpp>


namespace comET{
/*------------------------Argument---------------------------------*/

// this is the general case of Argument
template<typename Expression, typename dummy=void>
class Argument: public UnaryOperator<Expression>{
    public:
    Argument(const Expression &Expr):UnaryOperator<Expression>(Expr){}

    inline auto Re() const {return std::atan2( this->Expr.Im(), this->Expr.Re() );}
    inline auto Im() const {return 0 ;}


    inline complex<typename UnaryOperator<Expression>::numType> evaluate()const{return complex<typename UnaryOperator<Expression>::numType>(std::atan2( this->Expr.Im(), this->Expr.Re() ),0);}
};

template<typename Expression>
inline auto arg(const Expression &Expr){return Argument<Expression>(Expr);}


/*------------------------Argument of number---------------------------------*/
template<typename Expression>
class Argument<Expression, typename enable_if<std::is_arithmetic<Expression>::value,void>::type>{
    public:
    using numType = Expression;
    
    Expression value;
    Argument(const Expression &value):value(value){}

    inline auto Re() const {return std::atan2( 0,this->value );}
    inline auto Im() const {return 0 ;}


    inline complex<Expression> evaluate()const{return complex<Expression>(std::atan2( 0,this->value ), 0 );}
    friend std::ostream& operator<<(std::ostream& os, const Argument &expr)
    {os<<expr.evaluate();return os;} 

};




}




#endif