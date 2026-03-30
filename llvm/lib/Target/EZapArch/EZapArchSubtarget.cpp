#include "EZapArchSubtarget.h"
#include "EZapArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "ezaparch-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "EZapArchGenSubtargetInfo.inc"

EZapArchSubtarget::EZapArchSubtarget(const Triple &TT, const std::string &CPU,
                                     const std::string &FS, const TargetMachine &TM)
    : EZapArchGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS),
      TLInfo(TM, *this),
      FrameLowering(*this),
      RegInfo(),
      InstrInfo() {
  EZAPARCH_DUMP_CYAN
}