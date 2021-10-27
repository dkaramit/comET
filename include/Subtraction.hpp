#ifndef Sub_head
#define Sub_head
#include<iostream>
#include<cmath>

#include<complex.hpp>

#include<misc.hpp>
#include<BinaryOP.hpp>

namespace comET{
/*------------------------Subtraction---------------------------------*/

// this is the general case of Subtraction
template<typename leftHand, typename rightHand, typename dummy=void>
class Subtraction: public BinaryOperator<leftHand,rightHand>{
    public:
    
    Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline auto Re() const {return this->LH.Re() - this->RH.Re() ;}
    inline auto Im() const {return this->LH.Im() - this->RH.Im() ;}


    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(this->LH.Re() - this->RH.Re() , this->LH.Im() - this->RH.Im());}

};
//  operator+ returns a new instance of Subtraction. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator-(const leftHand &LH, const rightHand &RH){return Subtraction<leftHand,rightHand>(LH,RH);}




// Subtraction of complex + numeric-type (since all basic numeric types are real)
template<typename Expr, typename numericType> 
class Subtraction<Expr,numericType, typename enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<Expr,numericType>{ 
    public: 
    using leftHand = Expr;
    using rightHand = numericType;
    Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
  
    inline auto Re() const {return this->LH.Re() - this->RH ;}
    inline auto Im() const {return this->LH.Im() ;}

    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(this->LH.Re() - this->RH , this->LH.Im()) ;}
};

// Subtraction of numeric-type - complex (again all basic numeric types are real)
template<typename numericType, typename Expr> 
class Subtraction<numericType, Expr, typename  enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<numericType,Expr>{ 
    public: 
    using  leftHand = numericType;
    using rightHand = Expr;
    Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
  

    inline auto Re() const {return this->LH - this->RH.Re() ;}
    inline auto Im() const {return -this->RH.Im() ;}

    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(this->LH - this->RH.Re(), -this->RH.Im());}

};

}
#endif