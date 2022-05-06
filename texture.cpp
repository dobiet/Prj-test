#include "Texture.h"
#include "Game.h"

Texture::Texture()
{
    //Initialize
    //SDL_DestroyTexture( mTexture );
	mTexture = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}

Texture::~Texture()
{
    //Deallocate
    Free();
}

bool Texture::loadFromFile( std::string path )
{
    Free();

    SDL_Texture* newTexture= NULL;
    SDL_Surface* loadedSurface= IMG_Load(path.c_str());
    if( loadedSurface == NULL){
        std::cout<<"Unable to load image "<<path.c_str()<<"! SDL_Image Error: "<<'\n';
        IMG_GetError();
    }
    else{
        //Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Game::renderer, loadedSurface );
        if( newTexture == NULL ){
            std::cout<<"Unable to create texture from "<<path.c_str()<<"! SDL Error: "<<'\n';
            IMG_GetError();
        }
        else{
            //Get image dimensions
            rect_.w = loadedSurface->w;
            rect_.h = loadedSurface->h;
        }
        //Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
    }
    //Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void Texture::Free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		rect_.w = 0;
        rect_.h = 0;
	}
}

void Texture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void Texture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void Texture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void Texture::renderTexture( const SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { rect_.x, rect_.y, rect_.w, rect_.h};

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy( Game::renderer, mTexture, clip, &renderQuad );
}

