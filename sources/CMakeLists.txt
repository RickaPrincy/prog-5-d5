project(${EXAM_CLI_NAME} VERSION ${EXAM_CLI_VERSION} LANGUAGES CXX)

set(CLI_SOURCES main.cpp)

add_executable(${EXAM_CLI_NAME} ${CLI_SOURCES})

target_include_directories(${EXAM_CLI_NAME}
                           PRIVATE ${EXAM_SOURCE_DIR}/include)

set_target_properties(${EXAM_CLI_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                    "${CMAKE_BINARY_DIR}/bin")

if(EXAM_CLI_INSTALL)
  install(TARGETS ${EXAM_CLI_NAME} DESTINATION bin)
endif()
