#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <time.h>


/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
inline void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
}


/**
* Loads an image into a texture on the rendering device
* @param file The image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
inline SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr){
		logSDLError(std::cout, "LoadTexture");
	}
	return texture;
}


/**
* Loads an font
* @param file The font file to load
* @param fontSize The size to load the font into
* @return the loaded texture, or nullptr if something went wrong.
*/
inline TTF_Font* loadFont(const std::string &file, int fontSize){
	//Open the font
	TTF_Font *font = TTF_OpenFont(file.c_str(), fontSize);
	if (font == nullptr){
		logSDLError(std::cout, "TTF_OpenFont");
		return nullptr;
	}
	return font;
}


/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
* width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param w The width of the texture to draw
* @param h The height of the texture to draw
*/
inline void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}


/**
* Draw an SDL_Texture to an SDL_Renderer at some destination rect
* taking a clip of the texture if desired
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param dst The destination rectangle to render the texture to
* @param clip The sub-section of the texture to draw (clipping rect)
*		default of nullptr draws the entire texture
*/
inline void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect *dst,
	SDL_Rect *clip = nullptr)
{
	SDL_RenderCopy(ren, tex, clip, dst);
}


/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height and taking a clip of the texture if desired
* If a clip is passed, the clip's width and height will be used instead of
*	the texture's
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param clip The sub-section of the texture to draw (clipping rect)
*		default of nullptr draws the entire texture
*/
inline void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,
	SDL_Rect *clip = nullptr)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	if (clip != nullptr){
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else {
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}
	renderTexture(tex, ren, &dst, clip);
}


inline void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, double angle,
	SDL_Rect *clip = nullptr)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	if (clip != nullptr){
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else {
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}
	
	SDL_RenderCopyEx(ren, tex, clip, &dst, angle, nullptr, SDL_FLIP_NONE);
}

inline void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, double angle, int xr, int yr,
	SDL_Rect *clip = nullptr)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	if (clip != nullptr){
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else {
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}
	
	SDL_Point pnt = {xr, yr};
	
	SDL_RenderCopyEx(ren, tex, clip, &dst, angle, &pnt, SDL_FLIP_NONE);
}

/**
* Render the message we want to display to a texture for drawing
* @param message The message we want to display
* @param font The font we want to use to render the text
* @param color The color we want the text to be
* @param renderer The renderer to load the texture in
* @return An SDL_Texture containing the rendered message, or nullptr if something went wrong
*/
inline SDL_Texture* renderText(const std::string &message, TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
{
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr){
		logSDLError(std::cout, "TTF_RenderText");
		return nullptr;
	}


	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr){
		logSDLError(std::cout, "CreateTexture");
	}


	//Clean up the surface and font
	SDL_FreeSurface(surf);
	return texture;
}


inline long random()
{
	  /* initialize random seed: */
	  srand (time(NULL));
	  return rand();
}

inline int random(int a, int b)
{
	return random() % b + a;
}


inline bool collission(SDL_Rect box1, SDL_Rect box2)
{
	//Calculate the sides of rect A
	int t1 = box1.y, t2 = box2.y;
	int b1 = t1 + box1.h, b2 = t2 + box2.h;
	int l1 = box1.x, l2 = box2.x;
	int r1 = l1 + box1.w, r2 = l2 + box2.w;
	
	// Check edges
	if ((l1 > r2) || ( r1 < l2 ) || ( t1 > b2 ) || ( b1 < t2 ))
	{
		return false;
	}
	
	return true;
}

#endif // UTILS_H
