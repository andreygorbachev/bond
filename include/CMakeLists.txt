project("bond")

add_library(${PROJECT_NAME} INTERFACE
  bond.h
  utils.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)
