#ifndef LLVM_LIB_TARGET_EZAPARCH_EZAPARCHFRAMELOWERING_H
#define LLVM_LIB_TARGET_EZAPARCH_EZAPARCHFRAMELOWERING_H

#include "EZapArch.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {

class EZapArchFrameLowering : public TargetFrameLowering {
public:
  explicit EZapArchFrameLowering()
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(4), 0) {
    EZAPARCH_DUMP_GREEN
  }

  void emitPrologue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}
  void emitEpilogue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}

  bool hasFPImpl(const MachineFunction &MF) const override { return false; }
};

} // end namespace llvm

#endif