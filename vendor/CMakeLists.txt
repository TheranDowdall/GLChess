target_include_directories(${PROJECT_NAME} AFTER
                          PRIVATE glew/include
                          PRIVATE GLFW/include
                          PRIVATE glm/include
                          PRIVATE imgui/include
                          PRIVATE stb_image/include)

target_link_directories(${PROJECT_NAME} BEFORE
                           PRIVATE glew/lib
                           PRIVATE GLFW/lib
                           PRIVATE imgui/lib)

target_compile_definitions(${PROJECT_NAME} PRIVATE -DGLEW_STATIC)
target_link_libraries(${PROJECT_NAME} glfw3 opengl32.lib libglew32.lib IMGUI)
