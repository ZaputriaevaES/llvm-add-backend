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

class EZapArchTargetLowering : public TargetLowering {
public:
  explicit EZapArchTargetLowering(const TargetMachine &TM,
                                  const EZapArchSubtarget &STI);

  const char *getTargetNodeName(unsigned Opcode) const override;

  const EZapArchSubtarget &getSubtarget() const { return STI; }

private:
  const EZapArchSubtarget &STI;
};

} // end namespace llvm

#endif