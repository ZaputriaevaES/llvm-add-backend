#include "EZapArchSubtarget.h"
#include "EZapArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "ezaparch-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "EZapArchGenSubtargetInfo.inc"

EZapArchSubtarget::EZapArchSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                                     const StringRef &FS, const TargetMachine &TM)
    : EZapArchGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  EZAPARCH_DUMP_CYAN
}