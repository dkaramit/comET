#ifndef MISC_head
#define MISC_head


namespace comET{

using unInt = unsigned int;

template<bool C, typename T1, typename T2>
struct IF{using type=T1;};

template<typename T1, typename T2>
struct IF<false,T1,T2>{using type=T2;};

// enable_if::type is only defined if B==true. So, if we ask for enable_if<false,T>::type we should get 
// a compiler error, unless it is used in the context of SFINAE.  
template<bool B, typename T=void> struct enable_if {};
template<typename T> struct enable_if<true, T> { using type=T; };


//this chooses the largest numerical type used in the expression 
// (eg numType == double if the two expressions have leftHand::numType=int and leftHand::numType=double)
template<typename leftHand,typename rightHand, typename dummy=void>
struct largestType{
    using numType = typename IF<(sizeof(typename leftHand::numType) >= sizeof(typename  rightHand::numType)),
                   typename  leftHand::numType, typename rightHand::numType>::type;

};

template<typename Expr, typename LD>
struct largestType<Expr, LD, 
typename enable_if<std::is_arithmetic<LD>::value && (! std::is_arithmetic<Expr>::value), void >::type>{
    using numType = typename IF<(sizeof(typename Expr::numType) >= sizeof(LD)),
                   typename  Expr::numType, LD>::type;
};

template<typename LD, typename Expr>
struct largestType<LD, Expr, 
typename enable_if<std::is_arithmetic<LD>::value && (! std::is_arithmetic<Expr>::value), void >::type>{
    using numType = typename IF<(sizeof(typename Expr::numType) >= sizeof(LD)),
                   typename  Expr::numType, LD>::type;
};


template<typename LD1, typename LD2>
struct largestType<LD1, LD2, 
typename enable_if<std::is_arithmetic<LD1>::value && std::is_arithmetic<LD2>::value, void >::type>{
    using numType = typename IF<sizeof(LD1) >= sizeof(LD2), LD1, LD2>::type;
};




};

#endif