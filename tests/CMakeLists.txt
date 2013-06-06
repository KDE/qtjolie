include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../
                    ${CMAKE_CURRENT_BINARY_DIR}/../
                    ${CMAKE_CURRENT_SOURCE_DIR}/../includes
                    ${Qt5Core_INCLUDE_DIRS}
                    ${Qt5Widgets_INCLUDE_DIRS}
                    ${Qt5Network_INCLUDE_DIRS})

include(ECMMarkAsTest)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

MACRO(SODEP_UNIT_TESTS)
  FOREACH(_testname ${ARGN})
    add_executable(${_testname} ${_testname}.cpp) # TODO NOGUI
    target_link_libraries(${_testname} Qt5::Core Qt5::Test Qt5::Network QtJolie)
    ecm_mark_as_test(${_testname})
    add_definitions(-DDATA_DIR="\\"${CMAKE_CURRENT_SOURCE_DIR}\\"")
  ENDFOREACH(_testname)
ENDMACRO(SODEP_UNIT_TESTS)

MACRO(SODEP_EXECUTABLE_TESTS)
  FOREACH(_testname ${ARGN})
    add_executable(${_testname} ${_testname}.cpp) # TODO NOGUI
    target_link_libraries(${_testname} Qt5::Core Qt5::Network Qt5::Widgets QtJolie)
    add_definitions(-DDATA_DIR="\\"${CMAKE_CURRENT_SOURCE_DIR}\\"")
  ENDFOREACH(_testname)
ENDMACRO(SODEP_EXECUTABLE_TESTS)

SODEP_UNIT_TESTS(
  testvalue
  testfault
  testmessage
  testmetaservice
)

SODEP_EXECUTABLE_TESTS(
  testprinter
  calculatorservice
  trivialyahooclient
)

set(visiondriver_SRCS
   visiondriver.cpp
)

QT5_WRAP_UI(visiondriver_SRCS visiondriverwidget.ui)

add_executable(visiondriver ${visiondriver_SRCS})
target_link_libraries(visiondriver Qt5::Core Qt5::Network Qt5::Widgets QtJolie)

