#CMAKE 最小支持的版本号
cmake_minimum_required(VERSION 3.20)
#工程名字
project(lua_study_cmake)

#重要的配置文件…………
include(cmakeconf/compiler_conf.cmake)
include(cmakeconf/building_output.cmake)
#重要的配置文件…………

#添加子目录
add_subdirectory(sample)
add_subdirectory(lua_c)
add_subdirectory(lua_talk_c)