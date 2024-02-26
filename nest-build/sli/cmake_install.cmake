# Install script for directory: /p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install")
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
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/nest" TYPE SHARED_LIBRARY FILES
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli/libsli_readline.so.3.6.0-post0.dev0"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli/libsli_readline.so.3"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli::::::::::"
           NEW_RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so"
         RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/nest" TYPE SHARED_LIBRARY FILES "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli/libsli_readline.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so"
         OLD_RPATH "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli::::::::::"
         NEW_RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli_readline.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/nest" TYPE SHARED_LIBRARY FILES
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli/libsli.so.3.6.0-post0.dev0"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli/libsli.so.3"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
           NEW_RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so"
         RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/nest" TYPE SHARED_LIBRARY FILES "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli/libsli.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so"
         OLD_RPATH "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libsli.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli"
         RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli/sli")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli"
         OLD_RPATH "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-build/sli::::::::::"
         NEW_RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nest" TYPE FILE FILES
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/allocator.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/aggregatedatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/arraydatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/booldatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/callbackdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/charcode.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/datum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/dict.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/dictdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/dictstack.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/dictutils.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/doubledatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/fdstream.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/filesystem.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/functional.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/functiondatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/genericdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/integerdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/interpret.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/iostreamdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/lockptrdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/sharedptrdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/name.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slinames.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/namedatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/numericdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/oosupport.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/parser.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/parserdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/processes.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/scanner.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/sli_io.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/sliactions.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/sliarray.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slibuiltins.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slicontrol.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slidata.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slidict.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/sliexceptions.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slifunction.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/sligraphics.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slimath.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slimodule.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/sliregexp.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slistack.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slistartup.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slitype.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/slitypecheck.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/specialfunctionsmodule.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/stringdatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/symboldatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/tarrayobj.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/token.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/tokenarray.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/tokenstack.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/tokenutils.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/triedatum.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/typearray.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/typechk.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/utils.h"
    "/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator/sli/gnureadline.h"
    )
endif()

