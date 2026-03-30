#include "EZapArchISelLowering.h"
#include "EZapArch.h"
#include "EZapArchRegisterInfo.h"
#include "EZapArchSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "ezaparch-lower"

using namespace llvm;

EZapArchTargetLowering::EZapArchTargetLowering(const TargetMachine &TM,
                                               const EZapArchSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  EZAPARCH_DUMP_RED
  addRegisterClass(MVT::i32, &EZapArch::GPRRegClass);
}

const char *EZapArchTargetLowering::getTargetNodeName(unsigned Opcode) const {
  EZAPARCH_DUMP_RED
  switch (Opcode) {
  case EZapArchISD::CALL:
    return "EZapArchISD::CALL";
  case EZapArchISD::RET:
    return "EZapArchISD::RET";
  }
  return nullptr;
}