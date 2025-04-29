include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY http://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
    GIT_PROGRESS TRUE
    GIT_SHALLOW 1
)

FetchContent_MakeAvailable(Catch2)

file(GLOB_RECURSE TEST_SRC_FILES "*.cpp")

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_executable(tests ${TEST_SRC_FILES})
target_include_directories(tests PUBLIC "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(tests)
