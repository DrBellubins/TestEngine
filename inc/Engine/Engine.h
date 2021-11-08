#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>

// Time variables
float Time = 0.0f;
float DeltaTime = 0.0f;

// Main loop flag
bool quit = false;

// Input codes
Uint8* KeyStates;

// Functions
void Initialize();
void UpdateEvents();
bool LoadMedia();

#endif