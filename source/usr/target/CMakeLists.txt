cmake_minimum_required(VERSION 3.5)
set(_NAME request1)
project(${_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CURL "-lcurl")
find_package( CURL REQUIRED )
include_directories( ${CURL_INCLUDE_DIRS} )
list(APPEND SOURCES
    ../lib/Worker.cpp
    src/Request.cpp
)
add_executable(${_NAME} main_target.cpp)
target_sources(${_NAME} PRIVATE ${SOURCES})
target_link_libraries(${_NAME} ${CURL_LIBRARIES})
install(TARGETS ${_NAME} DESTINATION bin)