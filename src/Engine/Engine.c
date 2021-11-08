#include <stdio.h>
#include <windows.h>
#include <SDL2/SDL.h>

#include "Engine/Engine.h"
#include "Engine/Updates.h"
#include "Engine/GameWindow.h"

void Initialize()
{
	// Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// While application is running
		while (!quit)
		{
			Time += DeltaTime;
			
			Uint64 start = SDL_GetPerformanceCounter();
			UpdateEvents();
			Update();
			Draw();
		
			// Update the surface
			SDL_UpdateWindowSurface(gWindow);
			DeltaTime = (float)(SDL_GetPerformanceCounter() - start) /  (float)SDL_GetPerformanceFrequency();
		}
	}

	// Free resources and close SDL
	Close();
}

void UpdateEvents()
{
	SDL_Event gameEvent;

	while (SDL_PollEvent(&gameEvent) != 0)
	{
		switch (gameEvent.type)
		{
			case SDL_QUIT:
				quit = true;
				break;
			default:
				break;
		}
	}
}