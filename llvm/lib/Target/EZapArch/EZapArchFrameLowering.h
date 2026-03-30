#ifndef LLVM_LIB_TARGET_EZAPARCH_EZAPARCHFRAMELOWERING_H
#define LLVM_LIB_TARGET_EZAPARCH_EZAPARCHFRAMELOWERING_H

#include "EZapArch.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class EZapArchSubtarget;

class EZapArchFrameLowering : public TargetFrameLowering {
  const EZapArchSubtarget &STI;

public:
  explicit EZapArchFrameLowering(const EZapArchSubtarget &STI)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(4), 0),
        STI(STI) {
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