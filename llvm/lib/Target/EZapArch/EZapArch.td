include "llvm/Target/Target.td"
include "EZapArchRegisterInfo.td"
include "EZapArchInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def EZapArchInstrInfo : InstrInfo;
def EZapArch : Target {
  let InstructionSet = EZapArchInstrInfo;
}