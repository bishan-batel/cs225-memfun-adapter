#ifndef MEMFUN_ADAPTER_H
#define MEMFUN_ADAPTER_H
template<typename RetType, typename ClassType, typename ArgType>
class MFA_1arg {
  RetType (ClassType::*method)(ArgType);
public:
  MFA_1arg(RetType (ClassType::*pointer)(ArgType)) : method(pointer) {}

  RetType operator()(ClassType &type, ArgType arg) const { return (type.*method)(arg); }
};

// helper functions
// for non-const member function
template<typename RetType, typename ClassType, typename ArgType>
MFA_1arg<RetType, ClassType, ArgType> mfp_1arg(RetType (ClassType::*pointer)(ArgType)) {
  return MFA_1arg<RetType, ClassType, ArgType>(pointer);
}
#endif
