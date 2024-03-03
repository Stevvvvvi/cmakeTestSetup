cmake_minimum_required(VERSION 3.0)
# set(app_name )
project(HELLO)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})

include_directories(headers)

add_executable(output test.cpp src/swap.cpp)

target_link_libraries(output ${JSONCPP_LIBRARIES})

execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_SOURCE_DIR}/people.json
        ${CMAKE_BINARY_DIR}/people.json
)
