#include "EZapArchTargetMachine.h"
#include "EZapArch.h"
#include "TargetInfo/EZapArchTargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEZapArchTarget() {
  RegisterTargetMachine<EZapArchTargetMachine> X(getTheEZapArchTarget());
}

EZapArchTargetMachine::EZapArchTargetMachine(const Target &T, const Triple &TT,
                                             StringRef CPU, StringRef FS,
                                             const TargetOptions &Options,
                                             std::optional<Reloc::Model> RM,
                                             std::optional<CodeModel::Model> CM,
                                             CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  EZAPARCH_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// EZapArch Code Generator Pass Configuration Options.
class EZapArchPassConfig : public TargetPassConfig {
public:
  EZapArchPassConfig(EZapArchTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  bool addInstSelector() override {
    EZAPARCH_DUMP_CYAN
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *EZapArchTargetMachine::createPassConfig(PassManagerBase &PM) {
  EZAPARCH_DUMP_CYAN
  return new EZapArchPassConfig(*this, PM);
}