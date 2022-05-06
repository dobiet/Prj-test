#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "Texture.h"
#include "Weapon.h"
#include "commonFunc.h"
#include "Map.h"

//The dot that will move around on the screen
class Object : public Texture{
    public:
		enum walkType
        {
            WALK_NONE = 0,
            WALK_RIGHT = 1,
            WALK_LEFT = 2,
        };
        int status;
        Input input_type_;

		//Initializes the variables
		Object(const char* path, int x, int y);
		~Object();
        void updateObject();
		bool LoadImg( std::string path );

		//Moves the dot
		void move();
        void doObject(Map& map_game);
		//Shows the dot on the screen
		void render();
        void set_clips();

        SDL_Rect GetRectFrame();

		void checkMap(Map& map_game);
		void CheckToMap(Map& map_game);

        std::vector<Weapon*> get_weapon_list() const{ return weapon_list; }
        void set_weapon_list(std::vector<Weapon*> w_list){
            weapon_list = w_list;
        }

        void handleWeapon();
        void removeWeapon(const int& idx);


    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;

        SDL_Rect gSpriteClips[ num_frame ];
		int frame;

		int width_frame;
		int height_frame;

		bool on_ground;

        std::string figurePic;
        Texture objTexture;

		SDL_Rect frame_clip_[num_frame];
		std::vector<Weapon*> weapon_list;

};



#endif // OBJECT_H_INCLUDED
