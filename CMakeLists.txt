cmake_minimum_required(VERSION 2.8)

project(AQQueryResolver)

################################################################################
# libraries dependencies

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

# TODO add mysql client

################################################################################
# system specifics

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

# TODO add windows specifics

################################################################################
# util

# source files
file(GLOB aq_util_source_files aq/util/*.cpp)
file(GLOB exclude_files "aq/util/WIN32FileMapper.cpp")
list(REMOVE_ITEM aq_util_source_files ${exclude_files})

# aq-util static library
add_library(aq-util STATIC ${aq_util_source_files})

################################################################################
# parser

# Create target for the parser
ADD_CUSTOM_TARGET(bison-sql-parser)

# Create custom command for flex/lex
ADD_CUSTOM_COMMAND(
  TARGET bison-sql-parser
  SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/SQL92_Tok.l
  COMMAND echo "${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/SQL92_Tok.l"
  COMMAND flex
  ARGS --nounput -o${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/Lexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/SQL92_Tok.l
  OUTPUTS ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/Lexer.cpp
)

# Create custom command for bison/yacc
ADD_CUSTOM_COMMAND(
  TARGET bison-sql-parser
  SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/SQL92_Grm.y
  COMMAND bison
  ARGS -y -d ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/SQL92_Grm.y -o ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/Parser.cpp
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/Lexer.cpp
  OUTPUTS ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/Parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/Parser.hpp
)

SET_SOURCE_FILES_PROPERTIES(aq/parser/lex.yy.cpp GENERATED)
SET_SOURCE_FILES_PROPERTIES(aq/parser/Parser.cpp GENERATED)
SET_SOURCE_FILES_PROPERTIES(aq/parser/Parser.hpp GENERATED)

# aq-parser static library
add_library(aq-parser STATIC aq/parser/Parser.cpp
                             aq/parser/JeqParser.cpp
                             aq/parser/SQLParser.cpp
                             aq/parser/ID2Str.cpp)
add_dependencies(aq-parser bison-sql-parser)

################################################################################
# engine

# source files
file(GLOB aq_engine_source_files aq/engine/AQEngine.cpp
                                 aq/engine/AQEngineException.cpp
                                 aq/engine/AQMatrix.cpp)

# aq-engine static library
add_library(aq-engine STATIC ${aq_engine_source_files})

################################################################################
# query resolver

# source file
file(GLOB aq_query_resolver_source_files aq/*.cpp
                                         aq/db_loader/*.cpp
                                         aq/verbs/*.cpp)

# aq-query-resolver static library
add_library(aq-query-resolver STATIC ${aq_query_resolver_source_files})

################################################################################
# tools
file(GLOB aq_tools_source_files Tools/*.cpp)
file(GLOB exclude_files "Tools/aq_tests_batch.cpp")
list(REMOVE_ITEM aq_tools_source_files ${exclude_files})
add_executable(aq-tools ${aq_tools_source_files})
target_link_libraries(
    aq-tools
    aq-query-resolver
    aq-engine
    aq-parser
    aq-util
    ${Boost_LIBRARIES}
    -lmysqlcppconn)

################################################################################
# tests
file(GLOB aq_tests_source_files Tools/*.cpp)
file(GLOB exclude_files "Tools/aq_tools.cpp")
list(REMOVE_ITEM aq_tests_source_files ${exclude_files})
add_executable(aq-tests ${aq_tools_source_files})
target_link_libraries(
    aq-tests
    aq-query-resolver
    aq-engine
    aq-parser
    aq-util
    ${Boost_LIBRARIES}
    -lmysqlcppconn)
