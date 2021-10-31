#ifndef Pow_head
#define Pow_head
#include<iostream>
#include<cmath>

#include<complex.hpp>

#include<misc.hpp>
#include<BinaryOP.hpp>
#include<Multiplication.hpp>
#include<Division.hpp>
#include<Exp.hpp>
#include<Log.hpp>

namespace comET{
/*------------------------Pow---------------------------------*/

// this is the general case of Pow
template<typename leftHand, typename rightHand, typename dummy=void>
class Pow: public BinaryOperator<leftHand,rightHand>{
    public:
    
    Pow(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline auto Re() const {return exp(this->RH*log(this->LH)).Re();}
    inline auto Im() const {return exp(this->RH*log(this->LH)).Im();}


    inline complex<typename BinaryOperator<leftHand,rightHand>::numType> evaluate()const
    {return complex<typename BinaryOperator<leftHand,rightHand>::numType>(exp(this->RH*log(this->LH)).Re(),exp(this->RH*log(this->LH)).Im());}

};
//  operator/ returns a new instance of Pow. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto pow(const leftHand &LH, const rightHand &RH){return Pow<leftHand,rightHand>(LH,RH);}


}
#endif