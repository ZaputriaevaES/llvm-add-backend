#include "TargetInfo/EZapArchTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheEZapArchTarget() {
  static Target TheEZapArchTarget;
  return TheEZapArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEZapArchTargetInfo() {
  RegisterTarget<Triple::ezaparch> X(getTheEZapArchTarget(), "ezaparch",
                                     "EZapArch backend for LLVM course", "EZapArch");
}