# Install script for directory: /home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/lukkyguy/code/BachlorThesis/nest-install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nest" TYPE FILE FILES
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/beta_normalization_factor.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/block_vector.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/dict_util.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/enum_bitfield.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/iaf_propagator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/iterator_pair.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/lockptr.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/logging_event.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/logging.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/numerics.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/regula_falsi.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/sort.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/stopwatch.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/string_utils.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/libnestutil/vector_util.h"
    "/home/lukkyguy/code/BachlorThesis/nest-build/libnestutil/config.h"
    )
endif()

