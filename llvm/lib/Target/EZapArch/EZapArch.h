#ifndef LLVM_LIB_TARGET_EZapArch_EZapArch_H
#define LLVM_LIB_TARGET_EZapArch_EZapArch_H

#include "MCTargetDesc/EZapArchMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define EZAPARCH_DUMP(Color)
#define EZAPARCH_DUMP_YELLOW EZAPARCH_DUMP(llvm::raw_ostream::YELLOW)
#define EZAPARCH_DUMP_CYAN EZAPARCH_DUMP(llvm::raw_ostream::CYAN)
#define EZAPARCH_DUMP_MAGENTA EZAPARCH_DUMP(llvm::raw_ostream::MAGENTA)
#define EZAPARCH_DUMP_WHITE EZAPARCH_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class EZapArchTargetMachine;
class FunctionPass;
class EZapArchSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerEZapArchMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                       AsmPrinter &AP);
bool LowerEZapArchMachineOperandToMCOperand(const MachineOperand &MO,
                                            MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createEZapArchISelDag(EZapArchTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif