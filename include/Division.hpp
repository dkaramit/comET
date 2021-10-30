#ifndef Div_head
#define Div_head
#include<iostream>
#include<cmath>

#include<complex.hpp>

#include<misc.hpp>
#include<BinaryOP.hpp>
#include<Multiplication.hpp>
#include<Negation.hpp>

namespace comET{
/*------------------------Division---------------------------------*/

// this is the general case of Division
template<typename leftHand, typename rightHand, typename dummy=void>
class Division: public BinaryOperator<leftHand,rightHand>{
    public:
    
    Division(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline auto Re() const {return (this->LH.Re()*this->RH.Re() + this->RH.Im()*this->LH.Im())/(this->RH.Re()*this->RH.Re()+this->RH.Im()*this->RH.Im()) ;}
    inline auto Im() const {return (-(this->LH.Re()*this->RH.Im()) + this->LH.Im()*this->RH.Re())/(this->RH.Re()*this->RH.Re()+this->RH.Im()*this->RH.Im());}


    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(
        (this->LH.Re()*this->RH.Re() + this->RH.Im()*this->LH.Im())/(this->RH.Re()*this->RH.Re()+this->RH.Im()*this->RH.Im()) , 
        (-(this->LH.Re()*this->RH.Im()) + this->LH.Im()*this->RH.Re())/(this->RH.Re()*this->RH.Re()+this->RH.Im()*this->RH.Im()));}

};
//  operator/ returns a new instance of Division. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator/(const leftHand &LH, const rightHand &RH){return Division<leftHand,rightHand>(LH,RH);}


// this is the general case of Division: complex/numeric
template<typename Expr, typename numericType> 
class Division<Expr,numericType, typename enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<Expr,numericType>{ 
    public:

    using leftHand = Expr;
    using rightHand = numericType;

    Division(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline auto Re() const {return this->LH.Re()/this->RH ;}
    inline auto Im() const {return this->LH.Im()/this->RH;}


    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(
        this->LH.Re()/this->RH , 
        this->LH.Im()/this->RH);}

};

// this is the general case of Division: numeric/complex
template<typename numericType, typename Expr> 
class Division<numericType,Expr, typename enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<numericType,Expr>{ 
    public:

    using leftHand = numericType;
    using rightHand = Expr;

    Division(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline auto Re() const {return this->LH*this->RH.Re()/(this->RH.Re()*this->RH.Re()+this->RH.Im()*this->RH.Im()) ;}
    inline auto Im() const {return -this->LH*this->RH.Im()/(this->RH.Re()*this->RH.Re()+this->RH.Im()*this->RH.Im()) ;}


    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(
        this->LH*this->RH.Re()/(this->RH.Re()*this->RH.Re()+this->RH.Im()*this->RH.Im()) , 
        -this->LH*this->RH.Im()/(this->RH.Re()*this->RH.Re()+this->RH.Im()*this->RH.Im()));}

};



}
#endif