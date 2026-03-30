add_llvm_component_library(LLVMEZapArchDesc
  EZapArchMCTargetDesc.cpp
  EZapArchMCAsmInfo.cpp
  EZapArchInstPrinter.cpp

  LINK_COMPONENTS
  MC
  Support
  EZapArchInfo

  ADD_TO_COMPONENT
  EZapArch
)