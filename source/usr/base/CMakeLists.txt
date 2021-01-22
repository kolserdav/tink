cmake_minimum_required(VERSION 3.5)

project(request LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CURL "-lcurl")
list(APPEND SOURCES
    ../lib/Worker.cpp
    src/Response.cpp
)
find_package( CURL REQUIRED )
include_directories( ${CURL_INCLUDE_DIRS} )
add_executable(response main_response.cpp)
target_sources(response PRIVATE ${SOURCES})
target_link_libraries(response ${CURL_LIBRARIES})
install(TARGETS response DESTINATION bin)