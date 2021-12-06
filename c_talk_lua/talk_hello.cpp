extern "C" {
#include <stdio.h>
#include <assert.h>
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
}

int printHello(lua_State* L)
{

    //取出栈中的参数
    //如果想实现函数重载，可以对栈中的参数数量和参数类型进行判断后进行分别处理，这里只是为了展示lua对c的调用，
    //所以没有进行参数检查
     const char* arg0 = lua_tostring(L, -1);
    //输出Hello
    printf("Hello %s\n", arg0);
    //压入两个要返回的值
    char* result1 = "this is result1";
    lua_pushstring(L, result1);
    char* result2 = "this is result2";
    lua_pushstring(L, result2);
    //表示这个函数有2个返回值
    return 2;
}

static const struct luaL_Reg lib[] =
{
    {"printHello",printHello},
    {NULL,NULL}
};

int luaopen_testlib(lua_State *L)
{
    luaL_register(L,"testlib",lib);
    return 1;
}