CMAKE_MINIMUM_REQUIRED( VERSION 2.8.3 )

PROJECT( cpp_hello )

Find_Package(Lua51)

SET( CMAKE_CXX_FLAGS "-g" )

Include_directories(${LUA_INCLUDE_DIR})

ADD_EXECUTABLE( cpp_hello cpp_hello.cpp )

Target_link_libraries(cpp_hello ${LUA_LIBRARIES})
