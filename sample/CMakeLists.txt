#添加应用
add_executable(sample)
#目标的源文件
target_sources(sample
PUBLIC
    HelloLua.cpp
)
#目标包含目录
target_include_directories(sample
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

#目标链接包含的目录
target_link_directories(sample
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

#目标链接静态库
target_link_libraries(sample
PUBLIC
    lua53
)

