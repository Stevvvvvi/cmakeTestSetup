#
# mongo CXX driver and bson CXX library
#
# Source: https://github.com/mongodb/mongo-cxx-driver
# Tag: r3.8.0
# Build type: RelWithDebInfo
# Timestamp: 
#
message(DEBUG " Included CMakeLists.txt file for mongocxx and bsoncxx")

add_library(libbsoncxx STATIC IMPORTED)
add_library(libmongocxx STATIC IMPORTED)

if (AUD_PLATFORM_NAME STREQUAL linux_gcc) 
  set_target_properties(libbsoncxx PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/libbsoncxx-static.a
  )

  set_target_properties(libmongocxx PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/libmongocxx-static.a
  )

elseif (AUD_PLATFORM_NAME STREQUAL win32)
  set_target_properties(libbsoncxx PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/bsoncxx-static.lib
  )

  set_target_properties(libmongocxx PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/mongocxx-static.lib
  )

else()
  message(FATAL_ERROR "mongocxx and bsoncxx not supported for '${AUD_PLATFORM_NAME}' platform")
endif()

target_include_directories(libbsoncxx INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/include/bsoncxx/v_noabi
)
target_link_libraries(libbsoncxx INTERFACE
  libbson
)

target_include_directories(libmongocxx INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/include/mongocxx/v_noabi
)
target_link_libraries(libmongocxx INTERFACE
  libbsoncxx
  libmongoc 
)

add_library(mongocxx INTERFACE)
target_include_directories(mongocxx INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/include/bsoncxx/v_noabi
  ${CMAKE_CURRENT_LIST_DIR}/include/mongocxx/v_noabi
)
target_link_libraries(mongocxx INTERFACE
  libbsoncxx 
  libmongocxx
)

