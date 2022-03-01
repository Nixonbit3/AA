#include "SDL/include/SDL.h"
#include <stdio.h>
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



int main(int argc, char* argv[])
{ 



	SDL_Window* win;
	SDL_Renderer* renderer;

	//Inicio
	SDL_Init(SDL_INIT_VIDEO);

	//Create window

	win = SDL_CreateWindow(
		"Hello World", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		900, 
		650, 
		SDL_WINDOW_SHOWN
	);

	//renderer

	renderer = SDL_CreateRenderer(win, -1, 0);

	SDL_SetRenderDrawColor(renderer, 100, 25, 50, 100);
	
	SDL_Rect rectangle;

	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = 50;
	rectangle.h = 50;

	SDL_RenderFillRect(renderer, &rectangle);

	SDL_RenderClear(renderer);


	/*

		SDL_Event event;
		while (SDL_PollEvent(&event)) {  // poll until all events are handled!
			
			if (event.type == SDL_KEYDOWN) {
				SDL_Log("User just pressed down a key!");

			}
										 // decide what to do with this event.
		}

		// update game state, draw the current frame
	
		*/
	SDL_Delay(3000);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);

	SDL_Quit();

	return 0;

}








/*
#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720


typedef struct {
	SDL_Renderer* renderer;
	SDL_Window* window;
} App;

static App app;

void initSDL(void)
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}


void doInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			exit(0);
			break;

		default:
			break;
		}
	}
}

void prepareScene(void)
{
	SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
	SDL_RenderPresent(app.renderer);
}



int main (int argc, char** argv) {


	//memset(&app, 0, sizeof(App));

	initSDL();

	//atexit(cleanup);

	while (1)
	{
		prepareScene();

		doInput();

		presentScene();

		SDL_Delay(16);
	}

	return 0;


}*/

