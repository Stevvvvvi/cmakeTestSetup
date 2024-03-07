cmake_minimum_required(VERSION 3.0)
# set(app_name )
project(HELLO)

find_package(PkgConfig REQUIRED)
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})

include_directories(headers)
include_directories(~/libs/boost/1.82.0/include)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")
include_directories("${PROJECT_SOURCE_DIR}/dependents/mongocxx")


file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
list(APPEND ddm_LIBS
	openssl
	mongocxx
	boost_chrono
	boost_date_time
	boost_filesystem
	boost_regex
	boost_system
	boost_thread
	jsoncpp
	sodium
	simple-web-server
	dante_cpp_curl
	nlohmann_json
)

add_executable(${PROJECT_NAME} entitlement.cpp ${SOURCES})
add_compile_options(-Wall -std=c++11 -o3)

target_include_directories(${PROJECT_NAME} 
  PUBLIC ${Boost_INCLUDE_DIR}
  PUBLIC "/usr/local/include/mongocxx/v_noabi"
  PUBLIC "/usr/local/include/bsoncxx/v_noabi"
  PUBLIC "${PROJECT_SOURCE_DIR}/dependents/mongocxx"
)

target_link_libraries(${PROJECT_NAME} ${JSONCPP_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${LIBBSONCXX_LIBRARIES})


execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_SOURCE_DIR}/people.json
        ${CMAKE_BINARY_DIR}/people.json
)
