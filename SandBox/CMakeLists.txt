file(GLOB_RECURSE SANDBOX_SOURCE src/*.cpp src/*.h)

add_executable(VortakApp ${SANDBOX_SOURCE})

target_link_libraries(VortakApp PRIVATE VortakCore)
target_include_directories(VortakApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 1. Copy the Sandbox's user-level resources (if any)
add_custom_command(TARGET VortakApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/res
        $<TARGET_FILE_DIR:VortakApp>/res
)

# 2. Copy the Vortak engine-level resources (shaders, default models etc.)
add_custom_command(TARGET VortakApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Vortak/res
        $<TARGET_FILE_DIR:VortakApp>/res
)
