#ifndef LLVM_LIB_TARGET_EZAPARCH_MCTARGETDESC_EZAPARCHINFO_H
#define LLVM_LIB_TARGET_EZAPARCH_MCTARGETDESC_EZAPARCHINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace EZapArchOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace EZapArchOp

} // end namespace llvm

#endif