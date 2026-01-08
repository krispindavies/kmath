cmake_minimum_required(VERSION 3.5)
project(kmath VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

#########
# BUILD #
#########

add_library(kmath
  src/time.cpp
)

###########
# INSTALL #
###########

install(
  DIRECTORY
    include
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/
)

install(
  TARGETS
    kmath
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

########
# TEST #
########

add_executable(time_test test/time_test.cpp)
target_link_libraries(time_test kmath gtest)
add_test(time_test_run time_test)