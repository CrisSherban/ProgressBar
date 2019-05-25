cmake_minimum_required(VERSION 3.13)
project(Bar)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES ProgressBar.cpp ProgressBar.h FileTransfer.cpp FileTransfer.h
        DialogBox.cpp DialogBox.h Text.cpp Text.h)

add_executable(Bar main.cpp Observer.h Subject.h ProgressBar.cpp ProgressBar.h FileTransfer.cpp FileTransfer.h
        DialogBox.cpp DialogBox.h Text.cpp Text.h)

add_library(core ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(core ${SFML_LIBRARIES})
    #linking sfml to core so we can access the sfml library in gtests
endif ()

#linked stdc++fs static library for file reading
target_link_libraries(Bar core stdc++fs)