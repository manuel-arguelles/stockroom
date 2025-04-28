file(GLOB_RECURSE SRC_FILES "*.cpp")

add_executable(stockroom ${SRC_FILES})

target_include_directories(stockroom PRIVATE ${SQLite3_INCLUDE_DIRS})

target_link_libraries(stockroom PRIVATE 
    ${SQLite3_LIBRARIES})
