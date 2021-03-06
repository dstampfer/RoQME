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
# This file is generated once. Modify this file to your needs. 
# If you want the toolchain to re-generate this file, please 
# delete it before running the code generator.
#--------------------------------------------------------------------------
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
#TODO remove ace in verion 6.0.1
SET(SMARTSOFT_DEBS " libsmartxml (>=1.0.0), libace-6.0.1 (>=6.0.1)| libace-6.0.3,")
SET(SMARTSOFT_DEV_DEBS " libsmartxml-dev (>=1.0.0), libace-dev (>=6.0.1),")

MESSAGE("SMARTSOFT_DEBS is: ${SMARTSOFT_DEBS}")
MESSAGE("SMARTSOFT_DEV_DEBS is: ${SMARTSOFT_DEV_DEBS}")
GET_FILENAME_COMPONENT(CURRENTPATH ${CMAKE_CURRENT_LIST_FILE} PATH)
CONFIGURE_FILE(${CURRENTPATH}/../debian/control.user ${CURRENTPATH}/../debian/control @ONLY)
