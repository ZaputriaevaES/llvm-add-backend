#ifndef LLVM_LIB_TARGET_EZAPARCH_EZAPARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_EZAPARCH_EZAPARCHTARGETMACHINE_H

#include "EZapArchSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheEZapArchTarget;

class EZapArchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  EZapArchSubtarget Subtarget;

public:
  EZapArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                        StringRef FS, const TargetOptions &Options,
                        std::optional<Reloc::Model> RM,
                        std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                        bool JIT);

  const EZapArchSubtarget *getSubtargetImpl(const Function &) const override {
    EZAPARCH_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif