#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "Engine/Engine.h"
#include "Engine/Updates.h"
#include "Engine/GameWindow.h"

SDL_Surface* testSprite = NULL;
SDL_Rect testSpriteRect;
float testSpriteXPos = 0.0f;
float testSpriteYPos = 0.0f;

char CurrentDirectory[MAX_PATH];

int main(int argc, char* args[])
{
	printf("Hello world!");

	// Get executable directory
	char drive[3];
	char path[256];

	_splitpath_s(args[0], drive, sizeof(drive), path, sizeof(path), NULL, 0, NULL, 0); // Split
	sprintf(CurrentDirectory, "%s%s", drive, path); // Combine

	printf("Executable directory: %s\n", CurrentDirectory);

	// Load assets here
	if (!LoadMedia())
		printf("Failed to load media!\n");
	
	// Initialize engine
	Initialize();

	return 0;
}

void Update()
{
	testSpriteRect.x = (int)testSpriteXPos;
	testSpriteRect.y = (int)testSpriteYPos;

	if (KeyStates[SDL_SCANCODE_ESCAPE])
		printf("DeltaTime: %f\n", DeltaTime);
	
	if (KeyStates[SDL_SCANCODE_W])
		testSpriteYPos -= 100 * DeltaTime;
	
	if (KeyStates[SDL_SCANCODE_S])
		testSpriteYPos += 100 * DeltaTime;
	
	if (KeyStates[SDL_SCANCODE_A])
		testSpriteXPos -= 100 * DeltaTime;
	
	if (KeyStates[SDL_SCANCODE_D])
		testSpriteXPos += 100 * DeltaTime;
}

void Draw()
{
	// Apply the image
	SDL_BlitSurface(testSprite, NULL, gScreenSurface, &testSpriteRect);
}

void Close()
{
	// Deallocate surface
	SDL_FreeSurface(testSprite);
	testSprite = NULL;

	// Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// Quit SDL subsystems
	SDL_Quit();
}

bool LoadMedia()
{
	// Loading success flag
	bool success = true;

	// Load splash image
	testSprite = SDL_LoadBMP("Assets\\x.bmp");

	if (testSprite == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "x.bmp", SDL_GetError());
		success = false;
	}

	return success;
}