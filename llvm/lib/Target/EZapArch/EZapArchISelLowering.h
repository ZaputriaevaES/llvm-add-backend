#ifndef LLVM_LIB_TARGET_EZAPARCH_EZAPARCHISELLOWERING_H
#define LLVM_LIB_TARGET_EZAPARCH_EZAPARCHISELLOWERING_H

#include "EZapArch.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class EZapArchSubtarget;
class EZapArchTargetMachine;

namespace EZapArchISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace EZapArchISD

} // end namespace llvm

#endif