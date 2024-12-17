#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

using namespace std;

bool init();
void close();
// void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius);
// void drawFillCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius);
void createPoints(SDL_Renderer* renderer, ofstream* node);
void createWays(SDL_Renderer* rederer, ofstream* connetion);

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

int main(int argc, char* args[]) {
    ofstream node("node.txt", ios::app);
    ofstream connection("conection.txt", ios::app);
    if (!init()) {
        cout << "Failed to initialize!\n";
    } 
    else {
        SDL_Event e;
        bool quit = false;
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
        SDL_RenderClear(gRenderer);
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
        // SDL_Rect rect = {220, 140, 200, 200};
        // SDL_RenderFillRect(gRenderer, &rect);
        // SDL_RenderDrawLine(gRenderer, 30, 20, 40, 50);
        // SDL_RenderDrawPoint();
        
        SDL_RenderPresent(gRenderer);
        SDL_Delay(2000);
        while (!quit) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) quit = true;
            }
            SDL_Delay(100);
        }
    }
    close();
    return 0;
} 

bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << '\n';
        success = false;
    } else {
        gWindow = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        if (gWindow == NULL) {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
            success = false;
        }
    }
    return success;
}

void close() {
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_Quit();
}

// void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
//     int x = radius;
//     int y = 0;
//     int p = 1 - radius;

//     while (x >= y) {
//         // Draw symmetrical points
//         SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
//         SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
//         SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
//         SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
//         SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
//         SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
//         SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
//         SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);

//         y++;

//         if (p <= 0) {
//             p += 2 * y + 1;
//         } else {
//             x--;
//             p += 2 * y - 2 * x + 1;
//         }
//     }
// }

// void drawFillCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
//     int x = radius;
//     int y = 0;
//     int p = 1 - radius;

//     while (x >= y) {
//         // Draw horizontal lines to fill the circle row by row
//         SDL_RenderDrawLine(renderer, centerX - x, centerY + y, centerX + x, centerY + y);
//         SDL_RenderDrawLine(renderer, centerX - x, centerY - y, centerX + x, centerY - y);
//         SDL_RenderDrawLine(renderer, centerX - y, centerY + x, centerX + y, centerY + x);
//         SDL_RenderDrawLine(renderer, centerX - y, centerY - x, centerX + y, centerY - x);

//         y++;

//         if (p <= 0) {
//             p += 2 * y + 1;
//         } else {
//             x--;
//             p += 2 * y - 2 * x + 1;
//         }
//     }
// }

void createPoints(SDL_Renderer* renderer, ofstream* node) {
}