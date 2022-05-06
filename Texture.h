#pragma once

#include "include.h"
#include "commonFunc.h"

class Texture
{
	public:
		//Initializes variables
		Texture();

		//Deallocates memory
		~Texture();

        void setRect(const int& x, const int& y, const int& w, const int &h) {rect_.x = x, rect_.y = y; rect_.w= w; rect_.h= h;};
        void setRect(const int& x, const int& y) {rect_.x = x, rect_.y = y;}
        SDL_Rect getRect() const {return rect_;}
        SDL_Texture* getObject() {return mTexture;}
		//Loads image at specified path
		bool loadFromFile( std::string path );

        //Renders texture at given point
        void renderTexture( const SDL_Rect* clip );
		//Deallocates texture
		void Free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

	protected:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		SDL_Rect rect_;
};



//#endif // TEXTURE_H_INCLUDED

