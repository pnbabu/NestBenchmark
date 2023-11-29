# Install script for directory: /home/lukkyguy/code/BachlorThesis/nest-simulator/sli

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
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/nest" TYPE SHARED_LIBRARY FILES
    "/home/lukkyguy/code/BachlorThesis/nest-build/sli/libsli_readline.so.3.6.0-post0.dev0"
    "/home/lukkyguy/code/BachlorThesis/nest-build/sli/libsli_readline.so.3"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/lukkyguy/code/BachlorThesis/nest-build/sli::::::::::::::::"
           NEW_RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so"
         RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/nest" TYPE SHARED_LIBRARY FILES "/home/lukkyguy/code/BachlorThesis/nest-build/sli/libsli_readline.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so"
         OLD_RPATH "/home/lukkyguy/code/BachlorThesis/nest-build/sli::::::::::::::::"
         NEW_RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli_readline.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/nest" TYPE SHARED_LIBRARY FILES
    "/home/lukkyguy/code/BachlorThesis/nest-build/sli/libsli.so.3.6.0-post0.dev0"
    "/home/lukkyguy/code/BachlorThesis/nest-build/sli/libsli.so.3"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
           NEW_RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so"
         RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/nest" TYPE SHARED_LIBRARY FILES "/home/lukkyguy/code/BachlorThesis/nest-build/sli/libsli.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so"
         OLD_RPATH "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/nest/libsli.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli"
         RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/lukkyguy/code/BachlorThesis/nest-build/sli/sli")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli"
         OLD_RPATH "/home/lukkyguy/code/BachlorThesis/nest-build/sli::::::::::::::::"
         NEW_RPATH "\$ORIGIN/../lib/nest:\$ORIGIN/../../lib/nest:\$ORIGIN/../../../nest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sli")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nest" TYPE FILE FILES
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/allocator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/aggregatedatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/arraydatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/booldatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/callbackdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/charcode.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/datum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/dict.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/dictdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/dictstack.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/dictutils.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/doubledatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/fdstream.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/filesystem.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/functional.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/functiondatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/genericdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/integerdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/interpret.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/iostreamdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/lockptrdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/sharedptrdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/name.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slinames.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/namedatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/numericdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/oosupport.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/parser.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/parserdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/processes.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/scanner.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/sli_io.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/sliactions.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/sliarray.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slibuiltins.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slicontrol.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slidata.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slidict.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/sliexceptions.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slifunction.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/sligraphics.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slimath.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slimodule.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/sliregexp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slistack.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slistartup.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slitype.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/slitypecheck.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/specialfunctionsmodule.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/stringdatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/symboldatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/tarrayobj.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/token.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/tokenarray.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/tokenstack.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/tokenutils.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/triedatum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/typearray.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/typechk.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/utils.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/sli/gnureadline.h"
    )
endif()

