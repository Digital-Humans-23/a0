cmake_minimum_required(VERSION 3.5)

project(simple-math)
set(CRL_TARGET_NAME ${PROJECT_NAME})


file(
    GLOB
    CRL_SOURCES #
    "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/*.h" #
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" #
)

# basic dependencies
list(
    APPEND
    CRL_TARGET_DEPENDENCIES #
    "eigen" #
    "nlohmann_json" #
)

# target include dirs
list(APPEND CRL_TARGET_INCLUDE_DIRS #
     PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# target link libs
list(
    APPEND
    CRL_TARGET_LINK_LIBS #
    eigen
    nlohmann_json
)

# compile definitions
list(APPEND
     CRL_COMPILE_DEFINITIONS #
     PUBLIC
     VIRTUAL_HUMANS_MY_INFO="${CMAKE_CURRENT_LIST_DIR}/../../../my-info.json" #
)

message(STATUS "kllalal")
message(STATUS ${CMAKE_CURRENT_LIST_DIR})
message(STATUS ${CRL_COMPILE_DEFINITIONS})


set(CRL_TEST_SOURCES test/test.cpp)

# create target
create_crl_library(
    ${CRL_TARGET_NAME}
    "${CRL_SOURCES}" #
    "${CRL_TARGET_DEPENDENCIES}" #
    "${CRL_TARGET_INCLUDE_DIRS}" #
    "${CRL_TARGET_LINK_LIBS}" #
    "${CRL_COMPILE_DEFINITIONS}"
)

# create test
create_crl_test(
    ${CRL_TARGET_NAME}_test
    "${CRL_TEST_SOURCES}" #
    "${CRL_TARGET_NAME}" #
    "${CRL_TARGET_INCLUDE_DIRS}" #
    "${CRL_TARGET_NAME}" #
    "${CRL_COMPILE_DEFINITIONS}"
)
