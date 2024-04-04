# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/p/home/jusers/koll1/jusuf/NestBenchmark/Running/target_iaf_psc_alpha_plastic_optimized;/p/home/jusers/koll1/jusuf/NestBenchmark/Running/target_iaf_psc_alpha_plastic_optimized")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL "")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/p/software/jusuf/stages/2023/software/CMake/3.26.3-GCCcore-11.3.0/share/cmake-3.26/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "iaf_psc_alpha_nestmlplasticOptimizedmodule built using CMake")
set(CPACK_GENERATOR "TGZ")
set(CPACK_INSTALL_CMAKE_PROJECTS "/p/home/jusers/koll1/jusuf/NestBenchmark/Running/target_iaf_psc_alpha_plastic_optimized;iaf_psc_alpha_nestmlplasticOptimizedmodule;ALL;/")
set(CPACK_INSTALL_PREFIX "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator-install")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "iaf_psc_alpha_nestmlplasticOptimizedmodule 1.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "iaf_psc_alpha_nestmlplasticOptimizedmodule 1.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "/p/software/jusuf/stages/2024/software/binutils/2.40-GCCcore-12.3.0/bin/objcopy")
set(CPACK_OBJDUMP_EXECUTABLE "/p/software/jusuf/stages/2024/software/binutils/2.40-GCCcore-12.3.0/bin/objdump")
set(CPACK_OUTPUT_CONFIG_FILE "/p/home/jusers/koll1/jusuf/NestBenchmark/Running/target_iaf_psc_alpha_plastic_optimized/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/p/software/jusuf/stages/2023/software/CMake/3.26.3-GCCcore-11.3.0/share/cmake-3.26/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "NEST Module iaf_psc_alpha_nestmlplasticOptimizedmodule")
set(CPACK_PACKAGE_FILE_NAME "iaf_psc_alpha_nestmlplasticOptimizedmodule-1.0-Linux")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "iaf_psc_alpha_nestmlplasticOptimizedmodule 1.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "iaf_psc_alpha_nestmlplasticOptimizedmodule 1.0")
set(CPACK_PACKAGE_NAME "iaf_psc_alpha_nestmlplasticOptimizedmodule")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "NEST Initiative (http://www.nest-initiative.org/)")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_READELF_EXECUTABLE "/p/software/jusuf/stages/2024/software/binutils/2.40-GCCcore-12.3.0/bin/readelf")
set(CPACK_RESOURCE_FILE_LICENSE "/p/software/jusuf/stages/2023/software/CMake/3.26.3-GCCcore-11.3.0/share/cmake-3.26/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "/p/software/jusuf/stages/2023/software/CMake/3.26.3-GCCcore-11.3.0/share/cmake-3.26/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/p/software/jusuf/stages/2023/software/CMake/3.26.3-GCCcore-11.3.0/share/cmake-3.26/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES "\\.gitignore;\\.git/;\\.travis\\.yml;/build/;/_CPack_Packages/;CMakeFiles/;cmake_install\\.cmake;Makefile.*;CMakeCache\\.txt;CPackConfig\\.cmake;CPackSourceConfig\\.cmake")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/p/home/jusers/koll1/jusuf/NestBenchmark/Running/target_iaf_psc_alpha_plastic_optimized/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "iaf_psc_alpha_nestmlplasticOptimizedmodule")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/p/home/jusers/koll1/jusuf/NestBenchmark/Running/target_iaf_psc_alpha_plastic_optimized/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
