#include "renderer.hpp"

#include <raylib.h>
#include <rlgl.h>

#include "config.hpp"
#include "grid.hpp"

namespace rndr {

    Renderer::Renderer() {
        SetConfigFlags(WINDOW_FLAGS);
        InitWindow(WIDTH, HEIGHT, TITLE);
        SetTargetFPS(TARGET_FPS);

        f32 target { (Grid::Cube::SIZE * Grid::GRID_SIZE + Grid::Cube::SPACING * Grid::GRID_SIZE) / 2.0f };
        mCamera.position = { 10.0f, 10.0f, 10.0f };
        mCamera.target = { target, target, target };
        mCamera.fovy = 60.0f;
        mCamera.up = { 0.0f, 1.0f, 0.0f };
        mCamera.projection = CAMERA_PERSPECTIVE;

        Image original { LoadImage("assets/images/window_icon.png") };
        ImageFormat(&original, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);

        Image icons[3] { ImageCopy(original), ImageCopy(original), ImageCopy(original) };
        ImageResize(&icons[0], 16, 16);
        ImageResize(&icons[1], 32, 32);
        ImageResize(&icons[2], 64, 64);

        SetWindowIcons(icons, 3);

        for (Image& img : icons) 
            UnloadImage(img);
        UnloadImage(original);

        mCubeMesh = GenMeshCube(Grid::Cube::SIZE, Grid::Cube::SIZE, Grid::Cube::SIZE);

        mShader = LoadShader("assets/shaders/instancing.vs", "assets/shaders/instancing.fs");
        if (!IsShaderValid(mShader)) {
            TraceLog(LOG_ERROR, "Falha ao carregar shader de instancing");
        }
        mShader.locs[SHADER_LOC_MATRIX_MODEL] = GetShaderLocationAttrib(mShader, "instanceTransform");

        mMaterial = LoadMaterialDefault();
        mMaterial.shader = mShader;
        mMaterial.maps[MATERIAL_MAP_DIFFUSE].color = Fade(BLUE, 0.4f);

        mTransforms = mGrid.getTranforms();
    }

    Renderer::~Renderer() {
        UnloadMesh(mCubeMesh);
        UnloadMaterial(mMaterial);
        CloseWindow();
    }

    void Renderer::run() {
        while (!WindowShouldClose()) {
            UpdateCamera(&mCamera, CAMERA_ORBITAL);
            BeginDrawing();

            ClearBackground(BLACK);

            BeginMode3D(mCamera);
            rlDisableDepthMask();
            DrawMeshInstanced(mCubeMesh, mMaterial, mTransforms.data(), static_cast<i32>(mTransforms.size()));
            rlEnableDepthMask();
            EndMode3D();

            #ifndef NDEBUG
            DrawFPS(10, 10);
            #endif

            EndDrawing();
        }
    }

}  // namespace rndr
