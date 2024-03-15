# Install script for directory: /p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/pynest

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator-install")
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
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator-install/lib64/python3.10/site-packages/nest/;/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator-install/lib64/python3.10/site-packages/nest/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator-install/lib64/python3.10/site-packages/nest" TYPE DIRECTORY FILES
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/pynest/nest/"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/pynest/nest/"
    REGEX "/versionchecker\\.py\\.in$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/nest/pynestkernel.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/nest/pynestkernel.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/nest/pynestkernel.so"
         RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/nest" TYPE MODULE FILES "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/pynest/pynestkernel.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/nest/pynestkernel.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/nest/pynestkernel.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/nest/pynestkernel.so"
         OLD_RPATH "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/nest:/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/sli:"
         NEW_RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/nest/pynestkernel.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/nest/examples/pynest" TYPE DIRECTORY FILES "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/pynest/examples/")
endif()

