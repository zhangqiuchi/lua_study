# 在c++程序当中调用lua的函数
```cpp
luaL_loadfile(L, "../../lua_talk_c/PrintHello.lua");//加载文件
lua_pcall(L, 0, 0, 0);//直接调用
```
************************************************************

```cpp
 //函数压栈
lua_getglobal(L, "PrintHello");
//参数压栈
lua_pushstring(L, "zhangqiuchi");
//调用函数
lua_pcall(L, 1, 2, 0);//1个参数 两个返回值
```
函数自己会很识趣的弹栈。。不用管从栈顶开始的-1，-2 就是两个返回值。读完返回值如果还要调用别的函数。可以考虑自行弹栈（可以参考lua_c里面的例子）？？lua_pop(L, -1); lua_pop(L, -1); //为啥两次都是-1呢？自己去看lua_pop的实现………lua_pop名不副实啊？
**************************************************************

```cpp
//取出两个返回结果并且输出
std::cout << lua_tostring(L, -2) << std::endl;
std::cout << lua_tostring(L, -1) << std::endl;
```