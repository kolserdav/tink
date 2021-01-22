cmake_minimum_required(VERSION 3.5)

project(request LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CURL "-lcurl")
find_package( CURL REQUIRED )
include_directories( ${CURL_INCLUDE_DIRS} )
list(APPEND SOURCES
    ../lib/Worker.cpp
    src/Request.cpp
)
add_executable(request main_target.cpp)
target_sources(request PRIVATE ${SOURCES})
target_link_libraries(request ${CURL_LIBRARIES})
install(TARGETS request DESTINATION bin)