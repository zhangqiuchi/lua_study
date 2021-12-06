#include <iostream>

extern "C"
{
    #include <assert.h>
    #include <lauxlib.h>
    #include <lua.h>
    #include <lualib.h>
}

int main(void)
{
    lua_State* L = luaL_newstate();

    //打开基础库
    luaopen_base(L);
    luaL_openlibs(L);

    //载入PrintHello.lua
    luaL_loadfile(L, "../../lua_talk_c/PrintHello.lua");
        //
    lua_pcall(L, 0, 0, 0);

    //函数压栈
    lua_getglobal(L, "PrintHello");
    //参数压栈
    lua_pushstring(L, "zhangqiuchi");
    //调用函数
    lua_pcall(L, 1, 2, 0);//1个参数 两个返回值
    //取出两个返回结果并且输出
    std::cout << lua_tostring(L, -2) << std::endl;
    std::cout << lua_tostring(L, -1) << std::endl;
    lua_close(L);

    return 0;
}