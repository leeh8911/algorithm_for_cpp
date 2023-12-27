cmake_minimum_required(VERSION 3.25)

cmake_path(GET CMAKE_SOURCE_DIR FILENAME PROJECT_NAME)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN_EXE ${PROJECT_NAME})
set(TEST_NAME ${PROJECT_NAME}_test)
set(LIB_NAME ${PROJECT_NAME}_lib)

# Set the C++ standard we will use
if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT /W3 /Od /Oi /Gy /Zi /EHsc")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /W3 /Od /Oi /Gy /Zi /EHsc")
else(MSVC)
endif(MSVC)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_program(CLANGTIDY clang-tidy)
if(CLANGTIDY)
message(STATUS "activate clang-tidy")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY "${CLANGTIDY};-extra-arg=-Wno-unknown-warning-option;-fix")
else()
message(SEND_ERROR "clang-tidy requested but executable not found")
endif()

add_subdirectory(src)

add_subdirectory(test)