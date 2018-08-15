#
# Copyright (C) 2016 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Build a static lib and copy it into distribution place for independent app to use
# we could not delete the bin directory is because android studio would error out
# when it checks target's existance. Only distribution place is used as import to app

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(hpsocket
            SHARED 
            src/HPSocket.cpp
            src/HttpAgent.cpp
            src/HttpClient.cpp
            src/HttpCookie.cpp
            src/HttpHelper.cpp
            src/HttpServer.cpp
            src/MiscHelper.cpp
            src/SocketHelper.cpp
            src/TcpAgent.cpp
            src/TcpClient.cpp
            src/TcpPackAgent.cpp
            src/TcpPackClient.cpp
            src/TcpPackServer.cpp
            src/TcpPullAgent.cpp
            src/TcpPullClient.cpp
            src/TcpPullServer.cpp
            src/TcpServer.cpp
            src/UdpCast.cpp
            src/UdpClient.cpp
            src/UdpServer.cpp
            src/common/BufferPool.cpp
            src/common/Event.cpp
            src/common/FuncHelper.cpp
            src/common/IODispatcher.cpp
            src/common/PollHelper.cpp
            src/common/RWLock.cpp
            src/common/FileHelper.cpp
            src/common/SysHelper.cpp
            src/common/Thread.cpp
            src/common/http/http_parser.cpp
            src/common/crypto/Crypto.cpp)

# copy out the lib binary and remove generated files
set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../distribution)
set_target_properties(hpsocket
                      PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY
                      "${distribution_DIR}/hpsocket/lib/${ANDROID_ABI}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG -D_SSL_DISABLED -D_NEED_HTTP -D_ZLIB_DISABLED -D_ICONV_DISABLED")

add_custom_command(TARGET hpsocket POST_BUILD
                   COMMAND "${CMAKE_COMMAND}" -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/include/"
                   "${distribution_DIR}/hpsocket/include/"
                   COMMENT "Copying gperf to output directory")