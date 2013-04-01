CMAKE_MINIMUM_REQUIRED( VERSION 2.8.3 )

PROJECT( helloworld )

Find_Package(Lua51)

Include_directories(${LUA_INCLUDE_DIR})

ADD_EXECUTABLE( helloworld helloworld.cpp )

Target_link_libraries(helloworld ${LUA_LIBRARIES})
