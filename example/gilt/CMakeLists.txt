project("bond-example-gilt")

add_executable(${PROJECT_NAME}
  gilts.cpp
  gilts.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  bond
)
