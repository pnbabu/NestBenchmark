# Install script for directory: /p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nest

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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nest" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nest")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nest"
         RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/nest/nest")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nest" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nest")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nest"
         OLD_RPATH "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/sli:::::::::::::"
         NEW_RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nest")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/nest" TYPE SHARED_LIBRARY FILES
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/nest/libnest.so.3.6.0-post0.dev0"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/nest/libnest.so.3"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so.3.6.0-post0.dev0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so.3"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/sli:::::::::::::"
           NEW_RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so"
         RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/nest" TYPE SHARED_LIBRARY FILES "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/nest/libnest.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so"
         OLD_RPATH "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-build/sli:::::::::::::"
         NEW_RPATH "\$ORIGIN/../lib64/nest:\$ORIGIN/../../lib64/nest:\$ORIGIN/../../../nest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/nest/libnest.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nest" TYPE FILE FILES "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nest/neststartup.h")
endif()

