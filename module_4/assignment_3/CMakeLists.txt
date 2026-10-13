cmake_minimum_required(VERSION 4.1)
project(Prg_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Prg_1 main.cpp
        src/Sequence.h
        src/BumpList.h
        src/BumpList.cpp)

include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.3
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_executable(SequenceTests tests/SequenceTests.cpp
        src/Sequence.h
        src/BumpList.h
        src/BumpList.cpp
)
target_link_libraries(SequenceTests PRIVATE Catch2::Catch2WithMain)
add_test(NAME SequenceTests COMMAND SequenceTests)
