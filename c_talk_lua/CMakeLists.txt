#add_library(c_talk_lua SHARED)

add_executable(c_talk_lua)
target_sources(c_talk_lua
PUBLIC
    talk_hello.cpp
    VMLJ.cpp
)

target_include_directories(c_talk_lua
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

target_link_directories(c_talk_lua
PUBLIC
    ${CMAKE_SOURCE_DIR}/lua
)

target_link_libraries(c_talk_lua
PUBLIC
    lua53
)

