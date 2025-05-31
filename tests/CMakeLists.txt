find_package(Catch2 3)

if(NOT Catch2_FOUND)
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
    
    
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif()

include(CTest)
include(Catch)

file(GLOB_RECURSE TEST_SRC_FILES "*.cpp")
set(TESTED_SRC_FILES "${CMAKE_SOURCE_DIR}/src/database/sqlite_database.cpp")

add_executable(tests ${TEST_SRC_FILES} ${TESTED_SRC_FILES})
target_include_directories(tests PRIVATE ${SQLite3_INCLUDE_DIRS})
target_include_directories(tests PUBLIC "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain ${SQLite3_LIBRARIES})

catch_discover_tests(tests)
