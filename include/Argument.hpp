#ifndef ArgOp_head
#define ArgOp_head
#include<cmath>

#include<complex.hpp>


namespace comET{
/*------------------------Argument---------------------------------*/

// this is the general case of Argument
template<typename Expression, typename dummy=void>
class Argument{
    public:
    using numType = typename Expression::numType;
    Expression Expr;
    Argument(const Expression &Expr):Expr(Expr){}

    inline auto Re() const {return std::atan2( Expr.Im(), Expr.Re() );}
    inline auto Im() const {return 0 ;}


    inline complex<numType> evaluate()const{return complex<numType>(std::atan2( Expr.Im(), Expr.Re() ),0);}

    friend std::ostream& operator<<(std::ostream& os, const Argument &Expr)
    {os<<Expr.evaluate();return os;} 
};
//  operator/ returns a new instance of Argument. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename Expression>
inline auto Arg(const Expression &Expr){return Argument<Expression>(Expr);}

template<typename Expression>
class Argument<Expression, typename enable_if<std::is_arithmetic<Expression>::value,void>::type>{
    public:
    using numType = Expression;
    Expression Expr;
    Argument(const Expression &Expr):Expr(Expr){}

    inline auto Re() const {return std::atan2( 0,Expr );}
    inline auto Im() const {return 0 ;}


    inline complex<Expression> evaluate()const
    {return complex<Expression>(std::atan2( 0,Expr ), 0 );}

    friend std::ostream& operator<<(std::ostream& os, const Argument &Expr)
    {os<<Expr.evaluate();return os;} 

};




}




#endif