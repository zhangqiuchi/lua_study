/*
    一个简单的解释器
	和 lua 栈 之间 的 通信

lua 是如何执行的
	编写的lua文件 -> 通过语法分析器生成字节码（虚拟机指令） -> 通过lua虚拟机并执行字节码运行程序
*/

#include <iostream>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}
using namespace std;

//读取确定栈中的元素
static void stackDump(lua_State* L)
{
	int i;
	int top = lua_gettop(L);//得到栈顶
	//bug产生器
	//lua_pop(L, 1);//从栈中弹出几个元素
	for (i = 1; i <= top; i ++)
	{
		int t = lua_type(L, i);//栈顶的类型
		switch (t)
		{
			case LUA_TSTRING:
				printf("'%s'", lua_tostring(L, i));
				break;
			case LUA_TBOOLEAN:
				printf(lua_toboolean(L, i) ? "true":"false");
				break;
			case LUA_TNUMBER:
				printf("%g", lua_tonumber(L, i));
				break;
			default:
				printf("%s", lua_typename(L, t));
				break;
		}
		printf(" ");
	}
	printf("\n");
}

int main(void)
{
	char buff[256];
	int error;

	lua_State* L = luaL_newstate();//打开lua

	/*luaL_openlibs(L);//打开标准库

	while (fgets(buff, sizeof(buff), stdin) != NULL)
	{
       
		error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);//luaL_lodastring 编译用户输入的每一行内容没有错误返回0并向栈中压入编译后得到的函数
		//lua_pcall从栈中弹出编译后的元素，并以保护模式运行。没有错误返回0
		stackDump(L);
		if (error)
		{
			fprintf(stderr, "%s\n", lua_tostring(L, -1));
			lua_pop(L, 1);
		}
	}*/

	lua_pushboolean(L, 1);//给栈中压入true
	lua_pushnumber(L, 10);//给栈中压入10
	lua_pushnil(L);//给栈中压入nil
	lua_pushstring(L, "Hello");//给栈中压入字符串“Hello”

	stackDump(L);

	lua_pushvalue(L, -4);
	//将栈中从栈顶往下数第4个元素的拷贝值压入栈中
	stackDump(L);

	lua_replace(L, 3);
	//将栈顶弹出，并将栈中从栈底到栈顶第3个元素的值设为弹出的值
	stackDump(L);

	lua_settop(L, 5);
	//设置栈顶为从栈底到栈顶的第六个元素
	stackDump(L);

	lua_rotate(L, 3, 1);
	//将栈顶放置到第三个元素的位置， 栈中第三个元素开始每个元素的索引值加一
	stackDump(L);
	
	lua_remove(L, -3);
	//将从栈顶开始的第三个元素的值，移除。
	stackDump(L);

	lua_settop(L, -5);
	stackDump(L);

	lua_close(L);

	return 0;
}