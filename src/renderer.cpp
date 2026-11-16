#include "renderer.hpp"
#include "grid.hpp"
#include "cube.hpp"

namespace rndr {

Camera3D Renderer::createCamera() {
    Camera3D camera { };

    float target { (Cube::CUBE_SIZE * Grid::GRID_SIZE + Cube::CUBE_SPACING * Grid::GRID_SIZE) / 2.0f };
    camera.position = { 10.0f, 10.0f, 10.0f };
    camera.target = { target, target, target };
    camera.fovy = 60.0f;
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.projection = CAMERA_PERSPECTIVE;

    return camera;
}

void Renderer::renderGrid() {
    mGrid.foreachCell([&](GridPos pos) {
        renderCell(pos);
    });
}

void Renderer::renderCell(GridPos position) {
    DrawCube(getPosition(position), Cube::CUBE_SIZE, Cube::CUBE_SIZE, Cube::CUBE_SIZE, Fade(BLUE, 0.4f));
}

Vector3 Renderer::getPosition(const GridPos& pos) {
    return Vector3 {
        pos[0] * Cube::CUBE_SIZE + pos[0] * Cube::CUBE_SPACING,
        pos[1] * Cube::CUBE_SIZE + pos[1] * Cube::CUBE_SPACING,
        pos[2] * Cube::CUBE_SIZE + pos[2] * Cube::CUBE_SPACING,
    };
}

void Renderer::run() {
    InitWindow(WIDTH, HEIGHT, TITLE);
    Camera3D camera { createCamera() };
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_ORBITAL);
        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode3D(camera);
        renderGrid();
        EndMode3D();

        EndDrawing();
    }
}

}  // namespace rndr
