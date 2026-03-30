#include "EZapArch.h"
#include "TargetInfo/EZapArchTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "EZapArchGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "EZapArchGenInstrInfo.inc"

static MCRegisterInfo *createEZapArchMCRegisterInfo(const Triple &TT) {
  EZAPARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitEZapArchMCRegisterInfo(X, EZapArch::R0);
  return X;
}

static MCInstrInfo *createEZapArchMCInstrInfo() {
  EZAPARCH_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitEZapArchMCInstrInfo(X);
  return X;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEZapArchTargetMC() {
  EZAPARCH_DUMP_MAGENTA
  Target &TheEZapArchTarget = getTheEZapArchTarget();
  TargetRegistry::RegisterMCRegInfo(TheEZapArchTarget, createEZapArchMCRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(TheEZapArchTarget, createEZapArchMCInstrInfo);
}