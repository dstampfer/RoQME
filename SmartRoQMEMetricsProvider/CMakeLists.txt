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

INCLUDE(src-gen/ProjectSettings.cmake)

# in order to include additional sources for compilation (in a different folder than src), uncomment the lines below:
#FILE(GLOB SRCS <some-folder>/*.cc)
#LIST(APPEND USER_SRCS ${SRCS}) 
# alternativelly add individual source files: 
#LIST(APPEND USER_SRCS <some-folder>/MyClass.cc <some-folder>/AnotherClass.cc ...)
# in order to set additional include path (for the compiler to search for header files), uncomment:
#LIST(APPEND USER_INCLUDES <some-include-paths>)
LIST(APPEND USER_INCLUDES $ENV{ROQME_ROOT}/cpp/roqmeDDS/include)
LIST(APPEND USER_INCLUDES $ENV{ROQME_ROOT}/cpp/roqmeDDS/idl)
LIST(APPEND USER_INCLUDES $ENV{OSPL_HOME}/include/dcps/C++/isocpp2)
LIST(APPEND USER_INCLUDES $ENV{OSPL_HOME}/include/sys)
LIST(APPEND USER_INCLUDES $ENV{OSPL_HOME}/include)
LIST(APPEND USER_INCLUDES $ENV{OSPL_HOME}/include/dcps/C++/SACPP)

# in order to add already compiled libraries (which have a cmake package definition), uncomment:
#FIND_PACKAGE(Boost REQUIRED)
#LIST(APPEND USER_INCLUDES ${Boost_INCLUDE_DIRS})
#LIST(APPEND USER_LIBS ${Boost_LIBRARIES})/

LINK_DIRECTORIES($ENV{OSPL_HOME}/lib)
LINK_DIRECTORIES($ENV{ROQME_ROOT}/cpp/roqmeDDS/lib)

# in order to add further smartsoft utilities and/or communication-objects, uncomment:
#SMART_FIND_PACKAGE(SomePackageName)
#LIST(APPEND USER_INCLUDES ${SOMEPACKAGENAME_INCLUDE_DIRS})
LIST(APPEND USER_LIBS dcpssacpp dcpsgapi ddsdatabase ddsos ddskernel dcpsisocpp2 roqmedds)

INCLUDE(src-gen/BuildSettings.cmake)
ADD_DEFINITIONS( -std=c++11 )
