cmake_minimum_required(VERSION 3.14)
project(student-database)
set(SOURCES 
    src/database.cpp 
    src/student.cpp)

add_executable(${PROJECT_NAME} 
    ${SOURCES}    
    src/main.cpp)


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable( ${PROJECT_NAME}-ut 
    ${SOURCES}
    tests/tests.cpp )
target_link_libraries( ${PROJECT_NAME}-ut GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")