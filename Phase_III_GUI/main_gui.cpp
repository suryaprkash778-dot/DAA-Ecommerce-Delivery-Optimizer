// main_gui.cpp
#include "include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "E-Commerce Optimizer - GUI");
    SetTargetFPS(60);

    // Main game/GUI loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        // (Logic goes here)

        // Draw
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        // Title
        GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
        GuiLabel(Rectangle{ 250, 50, 300, 50 }, "Optimizer Dashboard");

        // Reset text size for buttons
        GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

        // Render a button and check if it was clicked
        if (GuiButton(Rectangle{ 300, 200, 200, 50 }, "Run Phase I")) {
            // Later, we will call your Knapsack/Dijkstra logic here
            TraceLog(LOG_INFO, "Phase I Button Clicked!");
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
    return 0;
}
