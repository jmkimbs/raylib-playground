#include <iostream>
#include "raylib.h"

void InitializeGame() {
    InitWindow(1280, 720, "Jonathan's [raylib] game");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
}

void SetupCamera() {
}

void LogEvents() {
    // std::cout << "FPS is: " << GetFPS() << std::endl;
}

void HandleInput(Camera *camera) {
    int keyPressed = GetKeyPressed();

    while (keyPressed != KEY_NULL) {
        std::cout << "Keycode pressed: " << keyPressed << std::endl;
        switch (keyPressed) {
            case KEY_L:
                SetTargetFPS(60);
                break;
            case KEY_K:
                SetTargetFPS(30);
                break;
            case KEY_P:
                (*camera).fovy += 1.0f;
                break;
            case KEY_W:
                std::cout << "Hopefully adjusting camera pos..." << std::endl;
                (*camera).position = (Vector3){ 100.0f, 100.0f, 100.0f };
                break;
            case KEY_S:
                std::cout << "Hopefully adjusting camera pos..." << std::endl;
                (*camera).position = (Vector3){ 50.0f, 50.0f, 50.0f };
                break;
        
        }
        keyPressed = GetKeyPressed();
    }
}

int main(void)
{
    InitializeGame();

    // Model babyBd = LoadModel("~/babybd.fbx");
    // Model babyBd = LoadModel("~/top/exportedmodels/0730000000.obj");

    Camera camera = { 0 };
    camera.position = (Vector3){ 50.0f, 50.0f, 50.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_CUSTOM);

    while (!WindowShouldClose())
    {
        LogEvents();
        UpdateCamera(&camera);
        HandleInput(&camera);


        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawGrid(20, 10.0f);
            EndMode3D();

            DrawFPS(10, 10);

            DrawText("Congrats! You created your first window!", 400, 340, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}