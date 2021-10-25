#ifndef Add_head
#define Add_head
#include<iostream>
#include<cmath>

#include<complex.hpp>

#include<misc.hpp>
#include<BinaryOP.hpp>

namespace comET{
/*------------------------Addition---------------------------------*/

// this is the general case of Addition
template<typename leftHand, typename rightHand, typename dummy=void>
class Addition: public BinaryOperator<leftHand,rightHand>{
    public:
    
    Addition(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline auto Re() const {return this->LH.Re() + this->RH.Re() ;}
    inline auto Im() const {return this->LH.Im() + this->RH.Im() ;}


    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(this->LH.Re() + this->RH.Re() , this->LH.Im() + this->RH.Im());}

};
//  operator+ returns a new instance of Addition. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator+(const leftHand &LH, const rightHand &RH){return Addition<leftHand,rightHand>(LH,RH);}




// Addition of complex + numeric-type (since all basic numeric types are real)
template<typename Expr, typename numericType> 
class Addition<Expr,numericType, typename enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<Expr,numericType>{ 
    public: 
    using leftHand = Expr;
    using rightHand = numericType;
    Addition(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
  
    inline auto Re() const {return this->LH.Re() + this->RH ;}
    inline auto Im() const {return this->LH.Im() ;}

    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(this->LH.Re() + this->RH , this->LH.Im()) ;}
};

// Addition of numeric-type + complex (again all basic numeric types are real)
template<typename numericType, typename Expr> 
class Addition<numericType, Expr, typename  enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<numericType,Expr>{ 
    public: 
    using  leftHand = numericType;
    using rightHand = Expr;
    Addition(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
  

    inline auto Re() const {return this->LH + this->RH.Re() ;}
    inline auto Im() const {return this->RH.Im() ;}

    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(this->LH + this->RH.Re(), this->RH.Im());}

};

}
#endif