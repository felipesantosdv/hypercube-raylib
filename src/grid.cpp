#include "grid.hpp"
#include <raylib.h>
#include <raymath.h>

namespace rndr {

Grid::Grid() {
    const f32 step { Cube::SIZE + Cube::SPACING };
    u64 i { };
    for (u32 x { }; x < GRID_SIZE; x++) {
        for (u32 y { }; y < GRID_SIZE; y++) {
            for (u32 z { }; z < GRID_SIZE; z++) {
                mTransforms[i++] = MatrixTranslate(x * step, y * step, z * step);
            }
        }
    }
}

const Grid::Transforms& Grid::getTranforms() const {
    return mTransforms;
}


}  // namespace rndr
