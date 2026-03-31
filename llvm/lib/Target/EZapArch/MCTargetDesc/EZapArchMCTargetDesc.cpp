#include "MCTargetDesc/EZapArchInfo.h"
#include "EZapArch.h"
#include "EZapArchInstPrinter.h"
#include "EZapArchMCAsmInfo.h"
#include "TargetInfo/EZapArchTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "EZapArchGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "EZapArchGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "EZapArchGenSubtargetInfo.inc"

static MCRegisterInfo *createEZapArchMCRegisterInfo(const Triple &TT) {
  EZAPARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitEZapArchMCRegisterInfo(X, EZapArch::R0);
  return X;
}

static MCInstrInfo *createEZapArchMCInstrInfo() {
  EZAPARCH_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitEZapArchMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createEZapArchMCSubtargetInfo(const Triple &TT,
                                                      StringRef CPU, StringRef FS) {
  EZAPARCH_DUMP_MAGENTA
  return createEZapArchMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createEZapArchMCAsmInfo(const MCRegisterInfo &MRI,
                                          const Triple &TT,
                                          const MCTargetOptions &Options) {
  EZAPARCH_DUMP_MAGENTA
  MCAsmInfo *MAI = new EZapArchELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(EZapArch::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createEZapArchMCInstPrinter(const Triple &T,
                                                  unsigned SyntaxVariant,
                                                  const MCAsmInfo &MAI,
                                                  const MCInstrInfo &MII,
                                                  const MCRegisterInfo &MRI) {
  EZAPARCH_DUMP_MAGENTA
  return new EZapArchInstPrinter(MAI, MII, MRI);
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEZapArchTargetMC() {
  EZAPARCH_DUMP_MAGENTA
  Target &TheEZapArchTarget = getTheEZapArchTarget();
  RegisterMCAsmInfoFn X(TheEZapArchTarget, createEZapArchMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheEZapArchTarget, createEZapArchMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheEZapArchTarget, createEZapArchMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheEZapArchTarget,
                                          createEZapArchMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheEZapArchTarget, createEZapArchMCInstPrinter);
}