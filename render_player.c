#include "main.h"

bool load_from_file(_Texture *T, const char *str_path)
{
	SDL_Texture *new_texture = NULL;
	SDL_Surface *surface = IMG_Load(str_path);

	if (!surface)
		printf("Unable to load image %s! SDL_image Error: %s\n",
				str_path, IMG_GetError());
	else
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(
				surface->format, 0, 0xFF, 0xFF));
		new_texture = SDL_CreateTextureFromSurface(ctx->renderer, surface);
		if (!new_texture)
			printf("Unable to create texture from %s! SDL Error: %s\n",
					str_path, SDL_GetError());
		else
		{
			T->w = surface->w;
			T->h = surface->h;
		}
		SDL_FreeSurface(surface);
	}
	T->Texture = new_texture;
	return (T->Texture != NULL);
}


void render_player(SDL_Renderer *R, _Texture *T,
				int x, int y, SDL_Rect *clip, double angle,
				SDL_Point *center, SDL_RendererFlip flip)
{
	SDL_Rect rect = {x, y, T->w, T->h};

	if (clip)
	{
		rect.w = clip->w;
		rect.h = clip->h;
	}
	SDL_RenderCopyEx(R, T->Texture, clip, &rect,
			angle, center, flip);
}

