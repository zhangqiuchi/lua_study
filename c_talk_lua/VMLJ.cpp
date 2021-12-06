#include <iostream>

extern "C" {
#include <assert.h>
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>
}

int luaopen_testlib(lua_State* L);

int main(void)
{
    lua_State* L = luaL_newstate();
    
    luaL_openlibs(L);//打开lua的标准库

    //luaopen_testlib(L);
    luaL_dofile(L, "../../c_talk_lua/listen_to_c.lua");//lua 加载
    lua_close(L);
    return 0;
}