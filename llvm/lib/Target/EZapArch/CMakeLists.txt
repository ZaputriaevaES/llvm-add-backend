add_llvm_component_group(EZapArch)

set(LLVM_TARGET_DEFINITIONS EZapArch.td)

tablegen(LLVM EZapArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM EZapArchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM EZapArchGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM EZapArchGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM EZapArchGenDAGISel.inc -gen-dag-isel)

add_public_tablegen_target(EZapArchCommonTableGen)

add_llvm_target(EZapArchCodeGen
  EZapArchTargetMachine.cpp
  EZapArchRegisterInfo.cpp
  EZapArchInstrInfo.cpp
  EZapArchSubtarget.cpp
  EZapArchAsmPrinter.cpp
  EZapArchISelDagToDag.cpp
  EZapArchISelLowering.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  EZapArchInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  EZapArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)