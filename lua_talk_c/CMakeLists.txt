add_executable(lua_talk_c)

target_sources(lua_talk_c
PUBLIC
    talk_hello.cpp
)

target_include_directories(lua_talk_c
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

target_link_directories(lua_talk_c
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

target_link_libraries(lua_talk_c
PUBLIC
    lua53
)
