#pragma once

#include <functional>

#include "config.hpp"

namespace rndr {

class Grid {
   public:
    static constexpr std::size_t GRID_SIZE { 10 };

    Grid() = default;

    void foreachCell(const std::function<void(GridPos)>& callable);

   private:
};

}  // namespace rndr
