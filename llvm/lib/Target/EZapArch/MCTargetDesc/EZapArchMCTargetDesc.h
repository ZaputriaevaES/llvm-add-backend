#ifndef LLVM_LIB_TARGET_EZAPARCH_MCTARGETDESC_EZAPARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_EZAPARCH_MCTARGETDESC_EZAPARCHMCTARGETDESC_H

// Defines symbolic names for EZapArch registers.
#define GET_REGINFO_ENUM
#include "EZapArchGenRegisterInfo.inc"

// Defines symbolic names for the EZapArch instructions.
#define GET_INSTRINFO_ENUM
#include "EZapArchGenInstrInfo.inc"

#endif