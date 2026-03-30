#ifndef LLVM_LIB_TARGET_EZAPARCH_EZAPARCHREGISTERINFO_H
#define LLVM_LIB_TARGET_EZAPARCH_EZAPARCHREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "EZapArchGenRegisterInfo.inc"

namespace llvm {

struct EZapArchRegisterInfo : public EZapArchGenRegisterInfo {
public:
  EZapArchRegisterInfo();
};

} // end namespace llvm

#endif