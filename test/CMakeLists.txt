project(bond-test)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}
  bond_calculator.cpp
  utils.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  bond
  GTest::gtest_main
)

export(TARGETS bond NAMESPACE Bond:: FILE BondConfig.cmake)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
