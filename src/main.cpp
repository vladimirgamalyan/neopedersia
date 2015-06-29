#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL.hh>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>
#include <SDL2pp/SDLImage.hh>
#include <SDL2pp/Texture.hh>
#include "World.h"
#include "PainterImpl.h"

int main(int /*argc*/, char** /*argv*/) try {
	// SDL stuff
	SDL2pp::SDL sdl(SDL_INIT_VIDEO);
    SDL2pp::SDLImage image(IMG_INIT_PNG);
	SDL2pp::Window window("neopedersia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE);
	SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    renderer.SetDrawBlendMode(SDL_BLENDMODE_BLEND);

	//unsigned int prev_ticks = SDL_GetTicks();

    PainterImpl painter(renderer);
    World world(painter);
    world.fill();

    const int MOVE_STEP = 16;

	// Main loop
	while (1) {
		//unsigned int frame_ticks = SDL_GetTicks();
		//unsigned int frame_delta = frame_ticks - prev_ticks;
		//prev_ticks = frame_ticks;

		// Process events
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return 0;
			} else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				    case SDLK_ESCAPE:
					    return 0;
                    case SDLK_UP:
                        world.moveMap(Vec2(0, -MOVE_STEP));
                        break;
                    case SDLK_DOWN:
                        world.moveMap(Vec2(0, MOVE_STEP));
                        break;
                    case SDLK_LEFT:
                        world.moveMap(Vec2(-MOVE_STEP, 0));
                        break;
                    case SDLK_RIGHT:
                        world.moveMap(Vec2(MOVE_STEP, 0));
                        break;
				}
			}
		}

        // Update
        world.update();

		// Render
		renderer.SetDrawColor(0, 0, 0);
		renderer.Clear();

        world.render();

		renderer.Present();

		// Frame limiter
		SDL_Delay(1);
	}

	return 0;
} catch (std::exception& e) {
	std::cerr << "Error: " << e.what() << std::endl;
	return 1;
} catch (...) {
	std::cerr << "Unknown error" << std::endl;
	return 1;
}
