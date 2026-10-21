cmake_minimum_required(VERSION 4.1)
project(Prg_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Prg_1 main.cpp
        src/Sequence.h
        src/BumpList.h
#        src/BumpList.cpp # was getting redefinition errors after adding #include BumpList.cpp to the end of the Bumplist.h file
)

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
#        src/BumpList.cpp # was getting redefinition errors after adding #include BumpList.cpp to the end of the Bumplist.h file
)
target_link_libraries(SequenceTests PRIVATE Catch2::Catch2WithMain)
add_test(NAME SequenceTests COMMAND SequenceTests)

# Add executable specifically for BumpList tests
add_executable(BumpListTests tests/BumplistTests.cpp
        src/Sequence.h
        src/BumpList.h
)
target_include_directories(BumpListTests PRIVATE src)
target_link_libraries(BumpListTests PRIVATE Catch2::Catch2WithMain)

# Sanitizer flags for testing deconstructor
target_compile_options(BumpListTests PRIVATE -fsanitize=address -g)
target_link_options(BumpListTests PRIVATE -fsanitize=address)

add_test(NAME BumpListTests COMMAND BumpListTests)

