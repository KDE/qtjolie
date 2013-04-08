cmake_minimum_required(VERSION 2.8.10.20130309)

project(QtJolie)

find_package(ECM 0.0.8 REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

find_package(KF5 5.0.0 REQUIRED MODULE COMPONENTS CMake Compiler InstallDirs)

include(FeatureSummary)

find_package(Qt4 REQUIRED QtCore)

add_definitions(${QT_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DQT_NO_CAST_FROM_ASCII -DQT_NO_CAST_TO_ASCII")

include(ECMSetupVersion)

ecm_setup_version(0 1 0 VARIABLE_PREFIX QTJOLIE
                        VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/qtjolie_version.h"
                        PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/QtJolieConfigVersion.cmake")

add_subdirectory(qtjolie)
add_subdirectory(includes)
add_subdirectory(tests)

# create a Config.cmake and a ConfigVersion.cmake file and install them
set(CMAKECONFIG_INSTALL_DIR "${CMAKECONFIG_INSTALL_PREFIX}/QtJolie")

include(CMakePackageConfigHelpers)

configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/QtJolieConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/QtJolieConfig.cmake"
  INSTALL_DESTINATION  ${CMAKECONFIG_INSTALL_DIR}
  PATH_VARS  INCLUDE_INSTALL_DIR CMAKE_INSTALL_PREFIX
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/qtjolie_version.h
        DESTINATION ${INCLUDE_INSTALL_DIR} COMPONENT Devel )

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/QtJolieConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/QtJolieConfigVersion.cmake"
  DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
  COMPONENT Devel
)

install(EXPORT QtJolieTargets DESTINATION "${CMAKECONFIG_INSTALL_DIR}" FILE QtJolieTargets.cmake NAMESPACE KF5:: )

