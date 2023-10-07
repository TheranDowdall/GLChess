target_precompile_headers(${PROJECT_NAME} PUBLIC cgpch.h) 

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src/Chess)

add_library(chessGame STATIC 
            Chess.h
            ${SRC_DIR}/Application.cpp
            ${SRC_DIR}/Window.cpp
            ${SRC_DIR}/Rendering/Renderer.cpp
            ${SRC_DIR}/Rendering/Shader.cpp
            ${SRC_DIR}/Rendering/VertexArray.cpp
            ${SRC_DIR}/Rendering/IndexBuffer.cpp
            ${SRC_DIR}/Rendering/Texture.cpp)

target_include_directories(chessGame BEFORE
                           PUBLIC  .
                           PUBLIC ${SRC_DIR}
                           PUBLIC ${SRC_DIR}/Rendering
                           PUBLIC ${SRC_DIR}/Game
                           PUBLIC ../vendor/glew/include
                           PUBLIC ../vendor/GLFW/include
                           PUBLIC ../vendor/glm/include
                           PUBLIC ../vendor/imgui/include
                           PUBLIC ../vendor/stb_image/include)

target_link_libraries(${PROJECT_NAME} chessGame)