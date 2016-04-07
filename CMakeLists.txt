cmake_minimum_required(VERSION 3.3)
Set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(flyfly)

set(SOURCE_FILES
    src/flyflygame/FlyFlyGame.cpp
    src/flyflygame/Rope.cpp
    src/math/Vector3.cpp
    src/math/Matrix4.cpp
    src/math/Quaternion.cpp
    src/graphics/camera/Camera.cpp
    src/graphics/material/Material.cpp
    src/graphics/geometry/Geometry.cpp
    src/graphics/geometry/BoxGeometry.cpp
    src/graphics/objects/Mesh.cpp
    src/graphics/objects/Object3D.cpp
    src/graphics/objects/Scene.cpp
    src/graphics/shader/Shader.cpp
    src/graphics/renderer/Renderer.cpp
    src/graphics/texture/Texture.cpp
    src/graphics/objloader/ObjLoader.cpp
    src/graphics/library/ShaderLibrary.cpp
    src/window/Window.cpp
    src/util/Util.cpp
    )
include_directories(
    src/flyflygame
    src/math
    src/graphics/renderer
    src/graphics/geometry
    src/graphics/camera
    src/graphics/material
    src/graphics/objects
    src/graphics/shader
    src/graphics/texture
    src/graphics/objloader
    src/graphics/library
    src/window
    src/util
    )
add_executable(flyfly src/main.cpp ${SOURCE_FILES})
target_link_libraries(flyfly GL GLEW glfw m assimp)
