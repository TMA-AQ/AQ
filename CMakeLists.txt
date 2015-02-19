cmake_minimum_required(VERSION 2.8)

project(AQQueryResolver)

################################################################################
# libraries dependencies

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.48.0 COMPONENTS program_options thread filesystem system timer regex REQUIRED)
find_package(FLEX 2.5.35 REQUIRED)
find_package(BISON 3.0.2 REQUIRED)
find_package(MySQLConnectorCPP REQUIRED)
find_package(Pqxx)

# Check syslog
include(CheckIncludeFiles)
check_include_files("syslog.h" HAVE_SYSLOG_H)
if(${HAVE_SYSLOG_H})
  add_definitions(-D__SYSLOG__)
endif(${HAVE_SYSLOG_H})

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${MYSQLCONNECTORCPP_INCLUDE_DIRS}
  $ENV{AQUTIL_SOURCE_DIR}
)

link_directories(
  ${LIBRARY_OUTPUT_PATH}
  ${Boost_LIBRARY_DIRS}
  $ENV{AQUTIL_LIBRARY_DIR}
)

################################################################################
# system specifics

set(CMAKE_CXX_FLAGS "--std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -Werror")
add_definitions(-DENABLE_AQL_PARSER)

# Mac OS X specific code
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "-lc++")
    set(CMAKE_SHARED_LINKER_FLAGS "-lc++")
    set(CMAKE_MODULE_LINKER_FLAGS "-lc++")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# TODO add windows specifics

################################################################################
# util

# source files
file(GLOB aq_util_source_files aq/util/AQLInfixSpiritParser.cpp
                               aq/util/AQLQuery.cpp
                               aq/util/AQLSpiritParser.cpp
                               aq/util/Base.cpp
                               aq/util/BaseDesc.cpp
                               aq/util/Column.cpp
                               aq/util/Database.cpp
                               aq/util/DateConversion.cpp
                               aq/util/DBTypes.cpp
                               aq/util/Exceptions.cpp
                               aq/util/GenericFileMapper.cpp
                               aq/util/Logger.cpp
                               aq/util/QueryReader.cpp
                               aq/util/Table.cpp
                               aq/util/Timer.cpp
                               aq/util/Utilities.cpp
                               aq/util/WIN32FileMapper.cpp)
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

# source files
file(GLOB aq_query_resolver_source_files aq/ApplyRowVisitor.cpp
                                         aq/AQFunctor.cpp
                                         aq/Column2Table.cpp
                                         aq/ColumnItem.cpp
                                         aq/DumpVisitor.cpp
                                         aq/NodeWritter.cpp
                                         aq/Optimizations.cpp
                                         aq/ParsException.cpp
                                         aq/QueryResolver.cpp
                                         aq/RowBinaryWritter.cpp
                                         aq/Row.cpp
                                         aq/RowSolver.cpp
                                         aq/RowTableWritter.cpp
                                         aq/RowTemporaryWritter.cpp
                                         aq/RowVerbProcess.cpp
                                         aq/RowWritter.cpp
                                         aq/Settings.cpp
                                         aq/SQLPrefix.cpp
                                         aq/statement_resolver.cpp
                                         aq/TemporaryColumnMapper.cpp
                                         aq/TreeUtilities.cpp
                                         aq/UpdateResolver.cpp)

# aq-query-resolver static library
add_library(aq-query-resolver STATIC ${aq_query_resolver_source_files}
                                     ${aq_loader_source_files}
                                     ${aq_verbs_source_files})

################################################################################
# aq loader

# source files
file(GLOB aq_loader_source_files aq/db_loader/DatabaseLoader.cpp)

# aq loader static library
add_library(aq-loader STATIC ${aq_loader_source_files})

################################################################################
# aq verbs

# source files
file(GLOB aq_verbs_source_files aq/verbs/AggregateVerbs.cpp
                                aq/verbs/ArithmeticVerbs.cpp
                                aq/verbs/AuxiliaryVerbs.cpp
                                aq/verbs/CaseVerb.cpp
                                aq/verbs/ComparisonVerbs.cpp
                                aq/verbs/ConversionVerbs.cpp
                                aq/verbs/DateVerbs.cpp
                                aq/verbs/JoinVerbs.cpp
                                aq/verbs/MainVerbs.cpp
                                aq/verbs/OverVerbs.cpp
                                aq/verbs/ScalarVerbs.cpp
                                aq/verbs/Verb.cpp
                                aq/verbs/VerbFactory.cpp
                                aq/verbs/VerbNode.cpp
                                aq/verbs/VerbResult.cpp)

# aq verbs static library
add_library(aq-verbs STATIC ${aq_verbs_source_files})

################################################################################
# test util

# source files
file(GLOB aq_test_util_source_files aq/tests/AQEngineTests.cpp
                                    aq/tests/DatabaseGenerator.cpp
                                    aq/tests/DatabaseHelper.cpp
                                    aq/tests/MySQLHelper.cpp
                                    aq/tests/QueryGenerator.cpp
                                    aq/tests/Report.cpp
                                    aq/tests/TestRunner.cpp
                                    aq/tests/Util.cpp)

if(${PQXX_FOUND})
  file(GLOB aq_test_util_source_files ${aq_test_util_source_files} aq/tests/PGSQLHelper.cpp)
endif(${PQXX_FOUND})

# aq-query-resolver static library
add_library(aq-test-util STATIC ${aq_test_util_source_files})
add_dependencies(aq-test-util aq-parser)

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
    aq-loader
    aq-verbs
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
    aq-loader
    aq-verbs
    aq-query-resolver
    aq-engine
    aq-parser
    aq-util
    ${Boost_LIBRARIES}
    ${MYSQLCONNECTORCPP_LIBRARIES}
    ${PQXX_LIBRARIES})

################################################################################
# tests parser
add_executable(sql-parser Tools/sql_parser.cpp)
add_dependencies(sql-parser aq-parser aq-util)
target_link_libraries(
    sql-parser
    aq-parser
    aq-util
    ${Boost_LIBRARIES})
