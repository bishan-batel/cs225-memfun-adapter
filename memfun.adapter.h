/**
 * name: Kishan S Patel
 * id: kishan.patel
 */
#ifndef MEMFUN_ADAPTER_H
#define MEMFUN_ADAPTER_H

/**
 * @brief Functor used as a conversion from a class's non const method to a function with a 'this' parameter
 */
template<typename RetType, typename ClassType, typename ArgType>
class MFA_1arg {
  RetType (ClassType::*method)(ArgType);

public:
  MFA_1arg(RetType (ClassType::*pointer)(ArgType)) : method(pointer) {}

  /**
   * @brief Calls the method on the instance 'self'
   */
  RetType operator()(ClassType &self, ArgType arg) const { return (self.*method)(arg); }
};

/**
 * @brief Creates a functor used as a conversion from a class's non const method to a function with a 'this' parameter
 */
template<typename RetType, typename ClassType, typename ArgType>
MFA_1arg<RetType, ClassType, ArgType> mfp_1arg(RetType (ClassType::*pointer)(ArgType)) {
  return MFA_1arg<RetType, ClassType, ArgType>(pointer);
}
#endif
