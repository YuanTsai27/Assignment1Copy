cmake_minimum_required(VERSION 3.22.0)
project(mechdonalds VERSION 0.1.0)

if(NOT(UNIX AND NOT APPLE))
    set(CMAKE_CXX_COMPILER /usr/bin/clang++)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)

# Add the main executable
add_executable(mechdonalds src/main.cpp)

# Add the subdirectories containing the source files
add_subdirectory(src)
add_subdirectory(src/app)
add_subdirectory(test)

enable_testing()

# Link the subdirectory targets to the main executable
target_link_libraries(mechdonalds SrcTarget SrcAppSupportTarget)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)