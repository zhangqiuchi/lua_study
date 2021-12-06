#include <iostream>
extern "C"
{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
    #include <lualib.h>
}

//这个函数比如就是
static int addc(lua_State* L)
{
    std::cout << "get top in addc: " << lua_gettop(L) << std::endl;
    int a, b, c;
    a = lua_tonumber(L, -1);
    b = lua_tonumber(L, -2);
    c = a + b;
    //压入结果
    lua_pushnumber(L, c);
    std::cout << "get top in addc, affter push result:" << lua_gettop(L) << std::endl;
    return 1;//表示有几个返回值
}

static int HelloWorld(lua_State* L)
{
    std::cout << "HelloWorld" << std::endl;
    return 0;//表示有几个返回值
}

static const struct luaL_Reg lib[] = {
    {"addc", addc},
    {"HelloWorld", HelloWorld},
    {NULL, NULL}
};

int luaopen_addlib(lua_State* L)
{
    luaL_register(L, "testadd", lib);//带参宏 是 加载 testadd 库 寄存器
    return 1;
}


