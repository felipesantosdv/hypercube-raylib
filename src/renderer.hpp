#pragma once

#include <raylib.h>

#include "grid.hpp"
#include "config.hpp"

namespace rndr {

class Renderer {
   public:
    Renderer();
    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    void run();

   private:
    static constexpr i32 HEIGHT { 720 };
    static constexpr i32 WIDTH { 1280 };
    static constexpr const char* TITLE { "Hypercube" };
    static constexpr u32 WINDOW_FLAGS { FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE };
    static constexpr i32 TARGET_FPS { 60 };

    Camera3D mCamera { };
    Mesh mCubeMesh { };
    Shader mShader { };
    Material mMaterial { };
    Grid mGrid { };
    Grid::Transforms mTransforms { };

};

}  // namespace rndr
