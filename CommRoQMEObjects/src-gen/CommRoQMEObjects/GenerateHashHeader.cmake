#--------------------------------------------------------------------------
# Code generated by the SmartSoft MDSD Toolchain
# The SmartSoft Toolchain has been developed by:
#  
# Christian Schlegel (schlegel@hs-ulm.de)
# University of Applied Sciences Ulm
# Prittwitzstr. 10
# 89075 Ulm (Germany)
#
# Information about the SmartSoft MDSD Toolchain is available at:
# www.servicerobotik-ulm.de
#
# Please do not modify this file. It will be re-generated
# running the code generator.
#--------------------------------------------------------------------------
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

SET(GEN_DIR ${CMAKE_CURRENT_LIST_DIR})

FILE(GLOB HASH_SRCS ${GEN_DIR}/*.hh ${GEN_DIR}/*.cc ${GEN_DIR}/../../CommRoQMEObjects/*.hh ${GEN_DIR}/../../CommRoQMEObjects/*.cc)
LIST(REMOVE_ITEM HASH_SRCS ${GEN_DIR}/hash.hh)
LIST(SORT HASH_SRCS)

FOREACH(SRC IN LISTS HASH_SRCS)
FILE(READ ${SRC} SRC_BUFFER)
FILE(APPEND HashSource.txt ${SRC_BUFFER})
ENDFOREACH()

FILE(MD5 HashSource.txt HASH_VALUE)
MESSAGE("HASH_VALUE of CommRoQMEObjects is: ${HASH_VALUE}")
FILE(REMOVE HashSource.txt)
CONFIGURE_FILE(${GEN_DIR}/hash.hh.in ${GEN_DIR}/hash.hh @ONLY)
