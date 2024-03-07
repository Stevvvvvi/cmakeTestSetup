#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mongo::bsoncxx_static" for configuration "RelWithDebInfo"
set_property(TARGET mongo::bsoncxx_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(mongo::bsoncxx_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libbsoncxx-static.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS mongo::bsoncxx_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_mongo::bsoncxx_static "${_IMPORT_PREFIX}/lib/libbsoncxx-static.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)