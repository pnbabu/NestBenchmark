# Install script for directory: /p/home/jusers/linssen1/jusuf/NestBenchmark/Running/target_plastic

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/nest")
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
  if(EXISTS "$ENV{DESTDIR}/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/nest/nestmlplasticmodule.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/nest/nestmlplasticmodule.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/nest/nestmlplasticmodule.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/nest/nestmlplasticmodule.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/nest" TYPE MODULE FILES "/p/home/jusers/linssen1/jusuf/NestBenchmark/Running/target_plastic/nestmlplasticmodule.so")
  if(EXISTS "$ENV{DESTDIR}/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/nest/nestmlplasticmodule.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/nest/nestmlplasticmodule.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "$ENV{DESTDIR}/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/nest/nestmlplasticmodule.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/p/home/jusers/linssen1/jusuf/NestBenchmark/Running/target_plastic/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
