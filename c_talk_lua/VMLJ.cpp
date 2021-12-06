#include <iostream>

extern "C"
{
#include <assert.h>
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
}

int luaopen_testlib(lua_State *L);

int main(void)
{
  char buff[256];
    lua_State* L = luaL_newstate();
    luaopen_base(L);
    luaL_openlibs(L);


    luaL_loadfile(L, "../../c_talk_lua/listen_to_c.lua");
    //
    lua_pcall(L, 0, 0, 0);

    
   
    lua_close(L);
    return 0;
}