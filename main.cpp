#include "raylib.h"
#include "RaylibRenderer.h"
#include "Player.h"

int main() {

    InitWindow(800, 600, "Raylib Test");
    SetTargetFPS(60);

    RaylibRenderer renderer;
    Player player("Hero", 100, 200);

    while (!WindowShouldClose()) {

        player.update();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        player.draw(renderer);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
