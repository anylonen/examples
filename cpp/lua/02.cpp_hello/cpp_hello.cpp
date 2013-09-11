
#include <iostream>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

using namespace std;

int Say_Hello(lua_State *LuaState)
{
    std::cout << "Hello, C++ World!" << std::endl;
}

int Say_Something(lua_State *LuaState)
{
    std::cout << lua_tostring(LuaState, 1) << std::endl;
}

int main(int argc, char* argv[])
{
    lua_State* L = luaL_newstate();

    luaL_openlibs(L);

    lua_register(L, "SayHello", Say_Hello);
    lua_register(L, "SaySomething", Say_Something);

    luaL_dofile(L, "cpp_hello.lua");

    lua_close(L);
    
    return 0;
}

