add_executable(lua_c)

target_sources(lua_c
PUBLIC
    lua_c.cpp
    addlib.cpp
)

target_include_directories(lua_c
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

target_link_directories(lua_c
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

target_link_libraries(lua_c
PUBLIC
    lua53
)

