#include "Window.h"

#include <SDL_ttf.h>
#include <iostream>

using namespace std;

int Window::XRES = -1;
int Window::YRES = -1;
int Window::FPS = -1;

Window::Window(int xres, int yres, int FPS, std::string name)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption(name.c_str(), NULL);
	TTF_Init();

	XRES = xres;
	YRES = yres;
	this->FPS = FPS;
	screen = SDL_SetVideoMode(XRES, YRES, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	font = TTF_OpenFont("TlwgTypo.ttf", 25);

	if (screen == NULL)
		return;
}

Window::~Window(void)
{
	SDL_FreeSurface(screen);
	SDL_Quit();
}

void Window::blitSurface(SDL_Surface* surface, int xPos, int yPos)
{
	SDL_Rect R;
	R.x = xPos;
	R.y = yPos;
	R.w = R.h = 0;

	SDL_BlitSurface(surface, NULL, screen, &R);
}

void Window::flipScreen()
{
	SDL_Flip(screen);
}

void Window::sync(unsigned int lastTime)
{
	int elapsed = SDL_GetTicks() - lastTime;
	if (elapsed < 1000 / Window::FPS)
		SDL_Delay(1000 / Window::FPS - elapsed); // Synchronize at Window::FPS count
}

SDL_Surface* Window::getSurface() const
{
	return screen;
}

TTF_Font* Window::getFont() const
{
	return font;
}