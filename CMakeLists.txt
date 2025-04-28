cmake_minimum_required(VERSION 3.16)
project(stockroom VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SQLite3 REQUIRED)

add_subdirectory(src)
