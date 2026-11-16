#pragma once

#include <raylib.h>

#include "grid.hpp"
#include "config.hpp"

namespace rndr {

class Renderer {
   public:
    static constexpr i32 HEIGHT = 720;
    static constexpr i32 WIDTH = 1280;
    static constexpr const char* TITLE = "Hypercube";

    Renderer() = default;
    ~Renderer() = default;

    Camera3D createCamera();
    void run();

   private:
    Grid mGrid { };

    void renderGrid();
    void renderCell(GridPos position);
    Vector3 getPosition(const GridPos& pos);
};

}  // namespace rndr
