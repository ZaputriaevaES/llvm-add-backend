#include "EZapArch.h"
#include "TargetInfo/EZapArchTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "EZapArchGenRegisterInfo.inc"

static MCRegisterInfo *createEZapArchMCRegisterInfo(const Triple &TT) {
  EZAPARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitEZapArchMCRegisterInfo(X, EZapArch::R0);
  return X;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEZapArchTargetMC() {
  EZAPARCH_DUMP_MAGENTA
  Target &TheEZapArchTarget = getTheEZapArchTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheEZapArchTarget, createEZapArchMCRegisterInfo);
}