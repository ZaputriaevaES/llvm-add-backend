add_llvm_component_group(EZapArch)

set(LLVM_TARGET_DEFINITIONS EZapArch.td)

tablegen(LLVM EZapArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM EZapArchGenInstrInfo.inc -gen-instr-info)

add_public_tablegen_target(EZapArchCommonTableGen)

add_llvm_target(EZapArchCodeGen
  EZapArchTargetMachine.cpp
  EZapArchRegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  EZapArchInfo

  ADD_TO_COMPONENT
  EZapArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)