#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>


class Window {
public:
    int x, y, w, h;
    bool fullscreen;
    SDL_Window* pWindow;
    SDL_Surface* pSurface;
    

    void setDefault()
    {
        x = 100;
        y = 100;
        w = 640;
        h = 480;
    }

    void create()
    {
        // Create Window and get its Surface
        this->pWindow = SDL_CreateWindow("Ozon", x, y, w, h, SDL_WINDOWPOS_CENTERED);
        this->pSurface = SDL_GetWindowSurface(pWindow);
    }

    void close()
    {
        SDL_FreeSurface(pSurface);
        pSurface = NULL;
        SDL_DestroyWindow(pWindow);
        pWindow = NULL;
        SDL_Quit();
    }

};


int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing. %s", SDL_GetError());
    }

    Window window;
    window.setDefault();
    window.create();

    std::cout << "Hello2 world!";
    return 0;
}