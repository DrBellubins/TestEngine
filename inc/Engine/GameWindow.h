#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <stdbool.h>
#include <SDL2/SDL.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Starts up SDL and creates window
extern bool init();

// The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
// The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

#endif