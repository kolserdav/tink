cmake_minimum_required(VERSION 3.5)
set(NAME ${EXECUTE})
project(${NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CURL "-lcurl")
list(APPEND SOURCES
    ../lib/Worker.cpp
    src/Response.cpp
)
find_package( CURL REQUIRED )
include_directories( ${CURL_INCLUDE_DIRS} )
add_executable(${NAME} main_response.cpp)
target_sources(${NAME} PRIVATE ${SOURCES})
target_link_libraries(${NAME} ${CURL_LIBRARIES})
install(TARGETS ${NAME} DESTINATION bin)