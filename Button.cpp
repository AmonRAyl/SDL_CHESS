#include "Button.h"
Button::Button(int x, int y, SDL_Renderer* renderer) :m_sRect{x,y,80,80},m_dRect{x,y,80,80}
{
	m_piece = NULL;
	SDL_Texture* t = IMG_LoadTexture(renderer, "/..../SDLPROJECTS/Chess/images/blackarrayinv2.png");//Change path
	m_T = t;
	t = IMG_LoadTexture(renderer, "/..../SDLPROJECTS/Chess/images/blackarray.png");//Change path
	m_Ts = t;
	m_aux = m_T;
	m_selected = false;
	m_dead = false;
}

Button::Button(int x, int y, SDL_Renderer* renderer,char white) :m_sRect{ x,y,80,80 }, m_dRect{ x,y,80,80 }
{
	m_piece = NULL;
	SDL_Texture* t = IMG_LoadTexture(renderer, "/..../SDLPROJECTS/Chess/images/whitearrayinv2.png");//Change path
	m_T = t;
	t = IMG_LoadTexture(renderer, "/..../SDLPROJECTS/Chess/images/whitearray.png");//Change path
	m_Ts = t;
	m_aux = m_T;
	m_selected = false;
	m_dead = false;
}

void Button::Setposition(int x, int y)
{
	m_dRect.x = x;
	m_dRect.y = y;
}

void Button::Getposition(int* x, int* y)
{
	*x = m_dRect.x;
	*y = m_dRect.y;
}

SDL_Texture* Button::Getmtexture()
{
	return m_T;
}
SDL_Texture* Button::Getstexture()
{
	return m_Ts;
}
SDL_Texture* Button::Getauxtexture()
{
	return m_aux;
}

void Button::Settexture(SDL_Texture* t)
{
	m_T = t;
}

void Button::Setselected(bool sel)
{
	m_selected = sel;
}

bool Button::Getselected()
{
	return m_selected;
}

void Button::Setdead(bool dead)
{
	m_dRect.w = 0;
	m_dRect.h = 0;
	m_dead = dead;
}

bool Button::Getdead()
{
	return m_dead;
}

SDL_bool Button::collision(SDL_Rect mouse)
{
	return SDL_HasIntersection(&m_dRect,&mouse);
}

void Button::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, m_T, &m_sRect, &m_dRect);
}

void Button::Setpiece(char piece)
{
	m_piece = piece;
}

char Button::Getpiece()
{
	return m_piece;
}
