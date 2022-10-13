#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>


class Window {
public:
    int x, y, w, h;
    bool fullscreen;
    bool quit;
    SDL_Window* pWindow;
    SDL_Surface* pSurface;

    void setDefault()
    {
        quit = false;
        x = 0;
        y = 0;
        w = 640;
        h = 480;
    }

    void create()
    {
        // Create Window and get its Surface
        pWindow = SDL_CreateWindow("Ozon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        w, h, SDL_WINDOW_SHOWN);
        if (pWindow == NULL)
        {
            std::cout << "pWindow is NULL!" << std::endl;
        }
        pSurface = SDL_GetWindowSurface(pWindow);
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


bool main_loop()
{

    
    return 0;
}


int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing. %s", SDL_GetError());
    }

    Window window{};
    window.setDefault();
    window.create();

    SDL_Surface* test = SDL_LoadBMP("");
    if (test == NULL) {
        std::cout << "Nie wczytalo sie 1." << std::endl;
    }

    SDL_BlitSurface(test, NULL, window.pSurface, NULL);

    SDL_UpdateWindowSurface(window.pWindow);

    SDL_Event event{};
    while (window.quit == false)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                window.quit = true;
            }
        }
    }



    std::cout << "Hell2 world!";
    return 0;
}