#include <iostream>
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}
extern int luaopen_addlib(lua_State* L);

using namespace std;

int main(void)
{
    lua_State* luaEnv = luaL_newstate();

    //载入addlib库
    luaopen_addlib(luaEnv);//1
 
    //压入需要调用的函数和参数
    lua_getglobal(luaEnv, "testadd");//2
    lua_getfield(luaEnv, -1, "addc");//3
    lua_pushinteger(luaEnv, 10);//4
    lua_pushinteger(luaEnv,12);//5
    cout << lua_gettop(luaEnv) << endl;//5
    lua_pcall(luaEnv, 2, 1, 0);//调用函数addc 两个参数一个返回值
    cout << lua_gettop(luaEnv) << endl;//3
    std::cout << lua_tonumber(luaEnv, -1) << std::endl;

    lua_pop(luaEnv, 1);
    lua_getfield(luaEnv, -1, "HelloWorld");
    lua_call(luaEnv, 0, 0, 0);//调用函数HelloWrold 零个参数零个返回值

    return 0;   
}