#ifndef LLVM_LIB_TARGET_EZAPARCH_MCTARGETDESC_EZAPARCHMCASMINFO_H
#define LLVM_LIB_TARGET_EZAPARCH_MCTARGETDESC_EZAPARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class EZapArchELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit EZapArchELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif