#include "grid.hpp"

namespace rndr {

void Grid::foreachCell(const std::function<void(GridPos)>& callable) {
    for (std::uint32_t x { }; x < GRID_SIZE; x++) {
        for (std::uint32_t y { }; y < GRID_SIZE; y++) {
            for (std::uint32_t z { }; z < GRID_SIZE; z++) {
                GridPos pos { x, y, z };
                callable(pos);
            }
        }
    }
}

}  // namespace rndr
