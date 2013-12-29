#include <iostream>
#include <string>
using namespace std;

#include <tolua++.h>
#include <lua.hpp>
#include <lualib.h>
#include <lauxlib.h>

#include "player.h"
#include "player_lua.h"

int main()
{
    //
    // Perform initalization. TODO: Add error checking for tolua?
    //
    lua_State *L = lua_open();

    if (NULL == L) {
        cout << "Error Initializing lua\n";
        return -1;
    }

    luaL_openlibs(L);   // initalize all lua standard library functions
    tolua_open(L);          // initalize tolua
    tolua_player_open(L);   // make Player class accessible from LUA

    //
    //  Run lua script to create player. This could also have been done using luaL_dostring().
    //
    luaL_dofile(L, "loadplayer.lua");

    //
    // Get the player object from lua
    //
    lua_getglobal(L, "player");
    Player* player = (Player*)tolua_tousertype(L, -1, 0);

    //
    // Display health and change value
    //
    cout << "\nC++: Player's health is " << player->getHealth() << " - Now setting it to 6";
    player->setHealth(6);
    cout << "\nC++: Player's health is now " << player->getHealth() << "\n";

    //
    // The player object in LUA should now be updated. This code could also be put inside a lua script.
    //
    luaL_dostring(L, "io.write(\"LUA: Player's health is \"..player:getHealth()..\" - Now setting it to 11\")");
    luaL_dostring(L, "player:setHealth(11)");
    cout << endl;
    luaL_dostring(L, "io.write(\"LUA: Player's health is now \"..player:getHealth())..\"\n\"");

    //
    // Perform cleanup.
    //
    lua_close(L);
    return 0;
}
