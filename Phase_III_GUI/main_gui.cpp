// main_gui.cpp
#include <string>
#include <vector>

#include "include/raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

// --- Include Algorithms from Phase I & II ---
#include "../Phase_I_Timestamped/domain.h"
#include "../Phase_I_Timestamped/dp_algorithms.h"
#include "../Phase_I_Timestamped/greedy_algorithms.h"
#include "../Phase_II/network_flow.h"
#include "../Phase_II/string_matching.h"

// --- GCC 14/15 COMPILER FIX ---
extern "C" int _stat64i32(const char* path, void* buffer);
extern "C" int stat64i32(const char* path, void* buffer) {
    return _stat64i32(path, buffer);
}
// ------------------------------

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "E-Commerce Optimizer - GUI");
    SetTargetFPS(60);

    // State variable to hold the output text for the screen
    std::string outputDisplay = "System Ready. Select an algorithm to run.";

    while (!WindowShouldClose()) { 
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        // Dashboard Title
        GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
        GuiLabel(Rectangle{ 250, 30, 300, 50 }, "Optimizer Dashboard");
        GuiSetStyle(DEFAULT, TEXT_SIZE, 18); // Reset size for buttons

        // --- LEFT PANEL: BUTTONS ---
        
        if (GuiButton(Rectangle{ 50, 120, 220, 50 }, "Run 0/1 Knapsack (DP)")) {
            std::vector<Order> orders = { 
                {"ORD1", 1, 5.0, 1}, {"ORD2", 2, 8.0, 1}, {"ORD3", 3, 12.0, 2} 
            };
            std::vector<Order> packed = packVehicleKnapsack(orders, 15.0);
            outputDisplay = "[PHASE I]\nKnapsack packed " + std::to_string(packed.size()) + 
                            " high-priority items\nwithin the 15.0kg weight limit.";
        }

        if (GuiButton(Rectangle{ 50, 190, 220, 50 }, "Run Dijkstra Routing")) {
            DeliveryNetwork network(3);
            network[0].push_back({1, 10.0, 5.0});
            network[0].push_back({2, 50.0, 10.0});
            network[1].push_back({2, 10.0, 5.0});
            std::vector<double> dist = calculateShortestPaths(network, 0);
            outputDisplay = "[PHASE I]\nShortest path to Zone 2 calculated.\nTotal Distance: " + 
                            std::to_string(dist[2]) + " km.";
        }

        if (GuiButton(Rectangle{ 50, 260, 220, 50 }, "Run Max Flow (Graph)")) {
            std::vector<std::vector<int>> capacityGraph = {
                {0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0}, {0, 4, 0, 0, 14, 0},
                {0, 0, 9, 0, 0, 20}, {0, 0, 0, 7, 0, 4}, {0, 0, 0, 0, 0, 0}
            };
            int flow = calculateMaxFlow(capacityGraph, 0, 5);
            outputDisplay = "[PHASE II]\nNetwork Flow Bottleneck Analyzed.\nMaximum Dispatch Capacity: " + 
                            std::to_string(flow) + " units/hr.";
        }

        if (GuiButton(Rectangle{ 50, 330, 220, 50 }, "Search Logs (KMP)")) {
            std::string eventLog = "System Start... ORD123 DISPATCHED... ALERT: ORD123 DELAYED AT HUB...";
            std::vector<int> matches = searchDeliveryEvent(eventLog, "DELAYED");
            outputDisplay = "[PHASE II]\nLog Scan Complete.\nAlert 'DELAYED' found at index: " + 
                            std::to_string(matches[0]);
        }

        // --- RIGHT PANEL: OUTPUT DISPLAY ---
        
        // Draw a dark background box for the text
        DrawRectangle(300, 120, 450, 260, Fade(BLACK, 0.8f));
        // Draw the dynamic output string inside the box
        DrawText(outputDisplay.c_str(), 320, 140, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
