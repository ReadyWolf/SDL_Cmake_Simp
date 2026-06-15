#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Hello SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    if (!window)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_KEYDOWN:  // Key pressed
                std::cout << "Key pressed: " << SDL_GetKeyName(event.key.keysym.sym) << "\n";
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;  // Exit on Escape
                break;

            case SDL_KEYUP:    // Key released
                std::cout << "Key released: " << SDL_GetKeyName(event.key.keysym.sym) << "\n";
                break;

            default:
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}