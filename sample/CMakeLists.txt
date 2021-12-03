#添加应用
add_executable(sample)
#目标的源文件
target_sources(sample
PUBLIC
    HelloLua.cpp
)

target_include_directories(sample
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

target_link_directories(sample
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

target_link_libraries(sample
PUBLIC
    lua53
)

