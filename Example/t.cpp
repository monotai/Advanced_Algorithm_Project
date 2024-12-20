#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fstream>
#include <iostream>
#include <string>

void createPoints(SDL_Renderer* renderer, std::ofstream& node) {
    // Example implementation: Create and render points
    for (int i = 0; i < 10; ++i) {
        int x = rand() % 800; // Random x coordinate
        int y = rand() % 600; // Random y coordinate
        SDL_RenderDrawPoint(renderer, x, y);
        node << x << " " << y << std::endl; // Save point to file
    }
}

void file(const std::string& nameFile) {
    std::ofstream node(nameFile);
    if (!node.is_open()) {
        std::cerr << "Failed to open file: " << nameFile << std::endl;
        return;
    }

    // Example usage of createPoints
    SDL_Window* window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return;
    }

    createPoints(renderer, node);

    SDL_RenderPresent(renderer);
    SDL_Delay(3000); // Display for 3 seconds

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    node.close();
}

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    file("points.txt");

    SDL_Quit();
    return 0;
}