#ifndef Mul_head
#define Mul_head
#include<iostream>
#include<cmath>

#include<complex.hpp>

#include<misc.hpp>
#include<BinaryOP.hpp>

namespace comET{
/*------------------------Multiplication---------------------------------*/

// this is the general case of Multiplication
template<typename leftHand, typename rightHand, typename dummy=void>
class Multiplication: public BinaryOperator<leftHand,rightHand>{
    public:
    
    Multiplication(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline auto Re() const {return this->LH.Re() * this->RH.Re() - this->LH.Im() * this->RH.Im();}
    inline auto Im() const {return this->LH.Re() * this->RH.Im() + this->LH.Im() * this->RH.Re() ;}


    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(this->LH.Re() * this->RH.Re() - this->LH.Im() * this->RH.Im() , this->LH.Re() * this->RH.Im() + this->LH.Im() * this->RH.Re());}

};
//  operator* returns a new instance of Multiplication. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator*(const leftHand &LH, const rightHand &RH){return Multiplication<leftHand,rightHand>(LH,RH);}


// Multiplication of complex * numeric-type (since all basic numeric types are real)
template<typename Expr, typename numericType> 
class Multiplication<Expr,numericType, typename enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<Expr,numericType>{ 
    public: 
    using leftHand = Expr;
    using rightHand = numericType;
    Multiplication(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
  
    inline auto Re() const {return this->LH.Re() * this->RH ;}
    inline auto Im() const {return this->LH.Im() * this->RH ;}

    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(this->LH.Re() * this->RH , this->LH.Im() * this->RH ) ;}
};



// Multiplication of numeric-type * complex (again all basic numeric types are real)
template<typename numericType, typename Expr> 
class Multiplication<numericType, Expr, typename  enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<numericType,Expr>{ 
    public: 
    using  leftHand = numericType;
    using rightHand = Expr;
    Multiplication(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
  

    inline auto Re() const {return this->RH.Re() * this->LH ;}
    inline auto Im() const {return this->RH.Im() * this->LH ;}

    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(this->RH.Re() * this->LH , this->RH.Im() * this->LH ) ;}

};




}
#endif