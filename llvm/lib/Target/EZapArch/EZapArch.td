include "llvm/Target/Target.td"
include "EZapArchRegisterInfo.td"
include "EZapArchInstrInfo.td"

def EZapArchInstrInfo : InstrInfo;
def EZapArch : Target {
  let InstructionSet = EZapArchInstrInfo;
}