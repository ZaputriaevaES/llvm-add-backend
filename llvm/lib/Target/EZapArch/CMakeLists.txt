add_llvm_component_group(EZapArch)

add_llvm_target(EZapArchCodeGen
  EZapArchTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  EZapArchInfo

  ADD_TO_COMPONENT
  EZapArch
  )

# add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)