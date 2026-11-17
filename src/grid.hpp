#pragma once

#include <raylib.h>
#include <array>

#include "config.hpp"

namespace rndr {

class Grid {
   public:
    static constexpr u32 GRID_SIZE { 10 };
    static constexpr u32 CELL_COUNT { GRID_SIZE * GRID_SIZE * GRID_SIZE };
    using Transforms = std::array<Matrix, CELL_COUNT>;
    struct Cube {
      static constexpr f32 SIZE { 0.5f };
      static constexpr f32 SPACING { 0.15f };
    };

    Grid();
    const Transforms& getTranforms() const;

   private:
   Transforms mTransforms { };
};

}  // namespace rndr
