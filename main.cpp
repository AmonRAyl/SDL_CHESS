#include "Button.h"

const int SCREEN_H = 640;
const int SCREEN_W = 640;

int main(int argc, char* argv[]) {

	SDL_Window* window = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized: " <<
			SDL_GetError();
	}
	else {
		std::cout << "SDL video system is ready to go\n";
	}

	window = SDL_CreateWindow("CHESS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer=nullptr;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface* surface = SDL_LoadBMP("/.../SDLPROJECTS/Chess/images/board640px.bmp");//Change path
	if (surface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "/....../SDLPROJECTS/Chess/images/board640.bmp", SDL_GetError());//Change path
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	// Create a board
	SDL_Rect board;
	board.x = 0;
	board.y = 0;
	board.w = 640;
	board.h = 640;
	//Mouse
	SDL_Rect mouse;
	mouse.w = 1;
	mouse.h = 1;
	//Create pieces
	Button * pieces[32];
	//Black pieces
	{
		pieces[0] = new Button(80 * 5, 0, renderer);
		pieces[0]->Setpiece('r');
		pieces[0]->Setposition(0, 0);
		
		pieces[7] = new Button(80 * 5, 0, renderer);
		pieces[7]->Setpiece('r');
		pieces[7]->Setposition(80 * 7, 0);

		pieces[1] = new Button(80 * 1, 0, renderer);
		pieces[1]->Setpiece('h');
		pieces[1]->Setposition(80, 0);

		pieces[6] = new Button(80 * 1, 0, renderer);
		pieces[6]->Setpiece('h');
		pieces[6]->Setposition(80 * 6, 0);

		pieces[3] = new Button(0, 0, renderer);
		pieces[3]->Setpiece('b');
		pieces[3]->Setposition(80 * 2, 0);

		pieces[5] = new Button(0, 0, renderer);
		pieces[5]->Setpiece('b');
		pieces[5]->Setposition(80 * 5, 0);

		pieces[4] = new Button(80 * 3, 0, renderer);
		pieces[4]->Setpiece('q');
		pieces[4]->Setposition(80 * 3, 0);

		pieces[2] = new Button(80 * 2, 0, renderer);
		pieces[2]->Setpiece('k');
		pieces[2]->Setposition(80 * 4, 0);
	}
	for (int i = 8; i < 16; i++)
	{
		pieces[i] = new Button(80 * 4, 0,renderer);
		pieces[i]->Setpiece('p');
		pieces[i]->Setposition(80 * (i-8), 80);
	}
	//White pieces
	{
		pieces[16] = new Button(80 * 5, 0, renderer, 'w');
		pieces[16]->Setpiece('R');
		pieces[16]->Setposition(0, 80 * 7);

		pieces[17] = new Button(80 * 5, 0, renderer, 'w');
		pieces[17]->Setpiece('R');
		pieces[17]->Setposition(80 * 7, 80 * 7);

		pieces[18] = new Button(80 * 1, 0, renderer, 'w');
		pieces[18]->Setpiece('H');
		pieces[18]->Setposition(80, 80 * 7);

		pieces[19] = new Button(80 * 1, 0, renderer, 'w');
		pieces[19]->Setpiece('H');
		pieces[19]->Setposition(80 * 6, 80 * 7);

		pieces[20] = new Button(0, 0, renderer, 'w');
		pieces[20]->Setpiece('B');
		pieces[20]->Setposition(80 * 2, 80 * 7);

		pieces[21] = new Button(0, 0, renderer, 'w');
		pieces[21]->Setpiece('B');
		pieces[21]->Setposition(80 * 5, 80 * 7);

		pieces[22] = new Button(80 * 3, 0, renderer, 'w');
		pieces[22]->Setpiece('Q');
		pieces[22]->Setposition(80 * 3, 80 * 7);

		pieces[23] = new Button(80 * 2, 0, renderer, 'w');
		pieces[23]->Setpiece('K');
		pieces[23]->Setposition(80 * 4, 80 * 7);
	}
	for (int i = 24; i < 32; i++)
	{
		pieces[i] = new Button(80 * 4, 0, renderer, 'w');
		pieces[i]->Setpiece('P');
		pieces[i]->Setposition(80 * (i - 24), 80 * 6);
	}

	// Infinite loop for our application
	bool gameIsRunning = true;
	int pieceSelected = -1;
	// Main application loop
	while (gameIsRunning) 
	{
		SDL_Event event;

		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);
		mouse.x = mouseX;
		mouse.y = mouseY;

		// Event loop
		while (SDL_PollEvent(&event)) 
		{
			// Handle each specific event
			if (event.type == SDL_QUIT) 
			{
				gameIsRunning = false;
			}
			if (event.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&mouseX, &mouseY);
				std::cout << mouseX << " : " << mouseY << std::endl;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT )
				{
					std::cout << "Left click down" << std::endl;
					if (pieceSelected == -1)
					{
						for (int i = 0; i < 32; i++)
						{
							if (pieces[i]->collision(mouse) == true)
							{
								std::cout << "Piece detected :" << pieces[i]->Getpiece() << std::endl;
								SDL_Texture *t= pieces[i]->Getstexture();
								pieces[i]->Settexture(t);
								pieceSelected = i;
								break;
							}
						}
					}
					else
					{
						//TODO logic of the game (check if a move is valid)
						if(true)
						{
							int posx, posy,i,j;
							posx = mouseX;
							posy = mouseY;
							i = -1;
							j = -1;
							while (posx > 0)
							{
								posx=posx- 80;
								i++;
							}
							while (posy > 0)
							{
								posy = posy - 80;
								j++;
							}
							pieces[pieceSelected]->Setposition(80*i, 80*j);
							for (int z = 0; z < 32; z++)
							{
								pieces[z]->Getposition(&posx,&posy);
								if (posx == 80 * i && posy == 80 * j && z != pieceSelected)
									pieces[z]->Setdead(true);
							}
							SDL_Texture *t=pieces[pieceSelected]->Getauxtexture();
							pieces[pieceSelected]->Settexture(t);
							pieceSelected = -1;
						}
					}
				}
			}
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					std::cout << "Left click up" << std::endl;
				}
			}
		}		
		//Draw Board
		SDL_RenderCopy(renderer, texture, NULL, &board);
		//Draw pieces
		for (int i = 0; i < 32; i++)
			pieces[i]->draw(renderer);
		//Draw mouse hitbox
		//SDL_RenderDrawRect(renderer, &mouse);
				
		// Finally show what we've drawn
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}
