include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/../
                    ${CMAKE_CURRENT_BINARY_DIR}
                    ${QT_INCLUDE_DIR})

set(qtjolie_LIB_SRCS
  abstractadaptor.cpp
  client.cpp
  clientthread.cpp
  value.cpp
  fault.cpp
  message.cpp
  metaservice.cpp
  pendingcall.cpp
  pendingcallwatcher.cpp
  pendingreply.cpp
  server.cpp
  serverthread.cpp
)

set(qtjolie_HEADERS
  abstractadaptor.h
  client.h
  value.h
  fault.h
  message.h
  metaservice.h
  pendingcall.h
  pendingcallwatcher.h
  pendingreply.h
  server.h
)

add_library(QtJolie SHARED ${qtjolie_LIB_SRCS})
generate_export_header(QtJolie)

target_link_libraries(QtJolie LINK_PUBLIC ${QT_QTCORE_LIBRARY} ${QT_QTNETWORK_LIBRARY})

set_target_properties(QtJolie PROPERTIES VERSION   ${QTJOLIE_VERSION_STRING}
                                         SOVERSION ${QTJOLIE_SOVERSION}
                                         LINK_FLAGS "-Wl,--no-undefined")

install(TARGETS QtJolie EXPORT QtJolieTargets ${INSTALL_TARGETS_DEFAULT_ARGS})

install( FILES
  ${qtjolie_HEADERS}

  ${CMAKE_CURRENT_BINARY_DIR}/qtjolie_export.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/QtJolie COMPONENT Devel
)

if(NOT WIN32) # pkgconfig file
   configure_file(${CMAKE_CURRENT_SOURCE_DIR}/QtJolie.pc.cmake ${CMAKE_CURRENT_BINARY_DIR}/QtJolie.pc @ONLY)
   install(FILES ${CMAKE_CURRENT_BINARY_DIR}/QtJolie.pc DESTINATION ${LIB_INSTALL_DIR}/pkgconfig)
endif(NOT WIN32)

configure_file("QtJolie.prf.cmake" "${CMAKE_BINARY_DIR}/QtJolie.prf" @ONLY)
install(FILES "${CMAKE_BINARY_DIR}/QtJolie.prf" DESTINATION ${CMAKE_INSTALL_PREFIX}/mkspecs/features)

