# Install script for directory: /home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/lukkyguy/code/NestBenchmark/nest-simulator-install")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/selftests/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/unittests/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/unittests/sli2py_ignore/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/regressiontests/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/regressiontests/sli2py_ignore/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/mpi_selftests/fail/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/mpi_selftests/pass/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/mpitests/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/musictests/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/lukkyguy/code/NestBenchmark/nest-build/testsuite/cpptests/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nest/testsuite" TYPE DIRECTORY FILES
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/selftests"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/unittests"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/regressiontests"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/mpitests"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/mpi_selftests"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/musictests"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/cpptests"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/pytests"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nest/testsuite" TYPE PROGRAM FILES "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/do_tests.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/nest_indirect"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/nest_serial"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nest/testsuite" TYPE FILE FILES
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/junit_xml.sh"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/run_test.sh"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/testsuite/summarize_tests.py"
    )
endif()

