#include "EZapArchRegisterInfo.h"
#include "EZapArch.h"
#include "EZapArchFrameLowering.h"
#include "EZapArchSubtarget.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "EZapArchGenRegisterInfo.inc"

EZapArchRegisterInfo::EZapArchRegisterInfo() : EZapArchGenRegisterInfo(EZapArch::R0) {
  EZAPARCH_DUMP_GREEN
}

const MCPhysReg *
EZapArchRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  EZAPARCH_DUMP_GREEN
  return CSR_EZapArch_SaveList;
}

BitVector EZapArchRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  EZAPARCH_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(EZapArch::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(EZapArch::R2);
  }
  return Reserved;
}

bool EZapArchRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool EZapArchRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                               int SPAdj, unsigned FIOperandNum,
                                               RegScavenger *RS) const {
  EZAPARCH_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("Frame index offset out of range");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register EZapArchRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  EZAPARCH_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? EZapArch::R2 : EZapArch::R1;
}

const uint32_t *
EZapArchRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                           CallingConv::ID CC) const {
  EZAPARCH_DUMP_GREEN
  return CSR_EZapArch_RegMask;
}