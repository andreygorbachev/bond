project("bond")

add_library(${PROJECT_NAME} INTERFACE
  bond_calculator.h
  utils.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)
