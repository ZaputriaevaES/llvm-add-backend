#ifndef LLVM_LIB_TARGET_EZAPARCH_EZAPARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_EZAPARCH_EZAPARCHTARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheEZapArchTarget;

class EZapArchTargetMachine : public CodeGenTargetMachineImpl {
public:
  EZapArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                        StringRef FS, const TargetOptions &Options,
                        std::optional<Reloc::Model> RM,
                        std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                        bool JIT);

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};
} // end namespace llvm

#endif