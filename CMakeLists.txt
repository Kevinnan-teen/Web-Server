cmake_minimum_required(VERSION 3.5)
project(webserver)

set(CMAKE_CXX_STANDARD 11)


set(CXX_FLAGS
        -Wall
        -std=c++11
        -lpthread
        -Wno-unused-parameter
        -O3
        )

link_libraries(pthread)

set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O3")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")


set(SOURCE_FILES
        src/http/HttpRequest.cpp
        src/http/HttpData.cpp
        src/http/HttpParse.cpp
        src/http/HttpResponse.cpp
        src/http/HttpServer.cpp
        src/Socket.cpp
        src/ThreadPool.cpp
        src/Timer.cpp
        src/Util.cpp
        src/Epoll.cpp
        src/main.cpp
        )

add_executable(webserver  ${SOURCE_FILES})