#ifndef LLVM_LIB_TARGET_EZAPARCH_EZAPARCHINSTRINFO_H
#define LLVM_LIB_TARGET_EZAPARCH_EZAPARCHINSTRINFO_H

#include "EZapArchRegisterInfo.h"
#include "MCTargetDesc/EZapArchInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "EZapArchGenInstrInfo.inc"

namespace llvm {

class EZapArchSubtarget;

class EZapArchInstrInfo : public EZapArchGenInstrInfo {
public:
  EZapArchInstrInfo();
};

} // end namespace llvm

#endif