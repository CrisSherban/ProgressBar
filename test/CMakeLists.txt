cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES runAllTests.cpp FileTransferTest.cpp ProgressBarTest.cpp)
add_executable(runAllTests ${SOURCE_FILES})
target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} core stdc++fs)