add_llvm_component_library(LLVMEZapArchDesc
  EZapArchMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  EZapArchInfo

  ADD_TO_COMPONENT
  EZapArch
)