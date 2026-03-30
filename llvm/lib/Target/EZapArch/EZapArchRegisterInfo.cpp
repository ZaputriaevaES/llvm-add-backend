#include "EZapArchRegisterInfo.h"
#include "EZapArch.h"
#include "EZapArchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "EZapArchGenRegisterInfo.inc"

EZapArchRegisterInfo::EZapArchRegisterInfo() : EZapArchGenRegisterInfo(EZapArch::R0) {
  EZAPARCH_DUMP_GREEN
}