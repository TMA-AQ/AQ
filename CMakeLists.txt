cmake_minimum_required(VERSION 2.8)

project(AQQueryResolver)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.48.0 COMPONENTS program_options thread filesystem system timer regex REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
  $ENV{AQUTIL_SOURCE_DIR}
)

link_directories(
  ${LIBRARY_OUTPUT_PATH}
  ${Boost_LIBRARY_DIRS}
  $ENV{AQUTIL_LIBRARY_DIR}
)

# Mac OS X specific code
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    SET(OperatingSystem "Darwin")
    set(CMAKE_CXX_FLAGS "-O0 -ggdb -std=c++11 -stdlib=libc++ -Wall")
    set(CMAKE_EXE_LINKER_FLAGS "-lc++")
    set(CMAKE_SHARED_LINKER_FLAGS "-lc++")
    set(CMAKE_MODULE_LINKER_FLAGS "-lc++")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# Linux g++
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(OperatingSystem "Linux")
    set(CMAKE_CXX_FLAGS "-O0 -ggdb -std=c++11 -Wall")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

file(GLOB aq_util_source_files aq/util/*.cpp)
file(GLOB aq_engine_source_files aq/engine/AQEngine.cpp aq/engine/AQMatrix.cpp)
file(GLOB_RECURSE aq_query_resolver_source_files aq/parser/SQL92_Tok.l aq/parser/SQL92_Grm.y aq/*.cpp)
list(APPEND aq_query_resolver_source "aq/parser/sql92_grm_tab.cpp")
list(REMOVE_ITEM aq_query_resolver_source_files ${aq_util_source_files})
list(REMOVE_ITEM aq_query_resolver_source_files ${aq_engine_source_files})

file(GLOB exclude_files "aq/tests/WhereComparator.cpp"
                        "aq/tests/WhereIn.cpp"
                        "aq/tests/WhereValidator.cpp"
                        "aq/util/WIN32FileMapper.cpp")
list(REMOVE_ITEM aq_util_source_files ${exclude_files})
list(REMOVE_ITEM aq_query_resolver_source_files ${exclude_files})

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/lex.yy.cpp")
  file(GLOB exclude_files "aq/parser/lex.yy.cpp")
  list(REMOVE_ITEM aq_query_resolver_source_files ${exclude_files})
endif()

# Create target for the parser
ADD_CUSTOM_TARGET(SQL_PARSER echo "Creating sql parser")

# Create custom command for flex/lex (note the outputs)
ADD_CUSTOM_COMMAND(
  TARGET SQL_PARSER
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  SOURCE aq/parser/SQL92_Tok.l
  COMMAND echo `pwd`
  COMMAND flex
  ARGS --nounput -o${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/lex.yy.cpp ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/SQL92_Tok.l
  OUTPUTS aq/parser/lex.yy.cpp
)

# Create custom command for bison/yacc (note the DEPENDS)
ADD_CUSTOM_COMMAND(
  TARGET SQL_PARSER
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  SOURCE aq/parser/SQL92_Grm.y
  COMMAND bison
  ARGS -y ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/SQL92_Grm.y -o ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/sql92_grm_tab.cpp
  DEPENDS aq/parser/lex.yy.cpp
  OUTPUTS aq/parser/sql92_grm_tab.cpp
)

SET(aq_query_resolver_source_files ${aq_query_resolver_source_files} aq/parser/sql92_grm_tab.cpp)
SET_SOURCE_FILES_PROPERTIES(aq/parser/lex.yy.cpp GENERATED)
SET_SOURCE_FILES_PROPERTIES(aq/parser/sql92_grm_tab.cpp GENERATED)

#  aq-util static library
add_library(aq-util STATIC ${aq_util_source_files})

# aq-util shared library
add_library(aq-util-shared SHARED ${aq_util_source_files})
target_link_libraries(aq-util-shared ${Boost_LIBRARIES})
set_target_properties(aq-util-shared PROPERTIES OUTPUT_NAME "aq-util")

# aq-engine static library
add_library(aq-engine STATIC ${aq_engine_source_files})

# aq-engine shared library
add_library(aq-engine-shared SHARED ${aq_engine_source_files})
target_link_libraries(aq-engine-shared ${Boost_LIBRARIES})
set_target_properties(aq-engine-shared PROPERTIES OUTPUT_NAME "aq-engine")

# aq-query-resolver static library
add_library(aq-query-resolver STATIC ${aq_query_resolver_source_files})

# aq-query-resolver shared library
add_library(aq-query-resolver-shared SHARED ${aq_query_resolver_source_files})
target_link_libraries(aq-query-resolver-shared aq-engine ${Boost_LIBRARIES})
set_target_properties(aq-query-resolver-shared PROPERTIES OUTPUT_NAME "aq-query-resolver")

# tools
file(GLOB aq_tools_source_files Tools/*.cpp)
file(GLOB exclude_files "Tools/aq_tests_batch.cpp")
list(REMOVE_ITEM aq_tools_source_files ${exclude_files})
add_executable(aq-tools ${aq_tools_source_files})
target_link_libraries(
    aq-tools
    aq-query-resolver-shared
    aq-engine-shared
    aq-util-shared
    ${Boost_LIBRARIES}
    -lmysqlcppconn)

# tests
file(GLOB aq_tests_source_files Tools/*.cpp)
file(GLOB exclude_files "Tools/aq_tools.cpp")
list(REMOVE_ITEM aq_tests_source_files ${exclude_files})
add_executable(aq-tests ${aq_tools_source_files})
target_link_libraries(
    aq-tests
    aq-query-resolver-shared
    aq-engine-shared
    aq-util-shared
    ${Boost_LIBRARIES}
    -lmysqlcppconn)
