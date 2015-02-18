cmake_minimum_required(VERSION 2.8)

project(AQQueryResolver)

################################################################################
# libraries dependencies

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.48.0 COMPONENTS program_options thread filesystem system timer regex REQUIRED)
find_package(FLEX 2.5.35)
find_package(BISON 3.0.2)
# include(CMakeUserFindMySQL)
# find_package(MySQL )

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

################################################################################
# system specifics

set(CMAKE_CXX_FLAGS "-O0 -ggdb -std=c++11 -Wall -DENABLE_AQL_PARSER -D__SYSLOG__")

# Mac OS X specific code
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    SET(OperatingSystem "Darwin")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -Werror")
    set(CMAKE_EXE_LINKER_FLAGS "-lc++")
    set(CMAKE_SHARED_LINKER_FLAGS "-lc++")
    set(CMAKE_MODULE_LINKER_FLAGS "-lc++")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# Linux g++
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(OperatingSystem "Linux")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -Werror")
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

BISON_TARGET(parser
             ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/SQL92_Grm.y
             ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/Parser.cpp
             COMPILE_FLAGS "-y")
FLEX_TARGET(scanner
            ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/SQL92_Tok.l
            ${CMAKE_CURRENT_SOURCE_DIR}/aq/parser/Lexer.cpp
            COMPILE_FLAGS "--nounput")
ADD_FLEX_BISON_DEPENDENCY(scanner parser)

# aq-parser static library
add_library(aq-parser STATIC ${BISON_parser_OUTPUTS}
                             ${FLEX_scanner_OUTPUTS}
                             aq/parser/JeqParser.cpp
                             aq/parser/SQLParser.cpp
                             aq/parser/ID2Str.cpp)
add_dependencies(aq-parser parser)
add_dependencies(aq-parser scanner)

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
# test util

# source file
file(GLOB aq_test_util_source_files aq/tests/AQEngineTests.cpp
                                    aq/tests/DatabaseGenerator.cpp
                                    aq/tests/DatabaseHelper.cpp
                                    aq/tests/MySQLHelper.cpp
                                    aq/tests/PGSQLHelper.cpp
                                    aq/tests/QueryGenerator.cpp
                                    aq/tests/Report.cpp
                                    aq/tests/TestRunner.cpp
                                    aq/tests/Util.cpp)

# aq-query-resolver static library
add_library(aq-test-util STATIC ${aq_test_util_source_files})

################################################################################
# tools
file(GLOB aq_tools_source_files Tools/AQEngineBasic.cpp
                                Tools/AQEngineSimulate.cpp
                                Tools/AQManager.cpp
                                Tools/CommandHandler.cpp
                                Tools/VerbBuilder.cpp)
add_executable(aq-tools Tools/aq_tools.cpp ${aq_tools_source_files})
add_dependencies(aq-tools aq-query-resolver aq-engine aq-parser aq-util)
target_link_libraries(
    aq-tools
    aq-query-resolver
    aq-engine
    aq-parser
    aq-util
    ${Boost_LIBRARIES})

################################################################################
# tests
add_executable(aq-tests Tools/aq_tests_batch.cpp ${aq_tools_source_files})
add_dependencies(aq-tests aq-query-resolver aq-engine aq-parser aq-util)
target_link_libraries(
    aq-tests
    aq-test-util
    aq-query-resolver
    aq-engine
    aq-parser
    aq-util
    ${Boost_LIBRARIES}
    -lmysqlcppconn
    -lpqxx
    -lpq)

################################################################################
# tests parser
add_executable(sql-parser Tools/sql_parser.cpp)
add_dependencies(sql-parser aq-parser aq-util)
target_link_libraries(
    sql-parser
    aq-parser
    aq-util
    ${Boost_LIBRARIES})
