#include <iostream>

extern "C"
{
  #include <stdio.h>
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
    //luaopen_base(L);
  luaL_openlibs(L);

  luaopen_testlib(L);
  luaL_dofile(L, "../../c_talk_lua/listen_to_c.lua");  
  lua_close(L);
  return 0;
}