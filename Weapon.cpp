#include "commonFunc.h"
#include "Weapon.h"

Weapon::Weapon()
{
    xVal = 0;
    yVal = 0;

    //isMoving = false;

    move_type = SIN_TYPE;
    time.start();
}

Weapon::~Weapon()
{

}

void Weapon::handleMove(const int& x_border, const int& y_border)
{
    double time_in_air = double(time.get_ticks())/300;
    if (weapon_dir == DIR_RIGHT)
    {
        rect_.x += speed_weapon*time_in_air*cos(angle);
    }
    else if (weapon_dir == DIR_LEFT)
    {
        rect_.x -= speed_weapon*time_in_air*cos(angle);
    }
    if(time_in_air <= ((speed_weapon*sin(angle))/GRAVITY_SPEED))
        rect_.y -= (speed_weapon*sin(angle)*time_in_air - GRAVITY_SPEED*time_in_air*time_in_air/2)*1.5;
    else rect_.y += (GRAVITY_SPEED*time_in_air*time_in_air/2)*0.6;


    if (rect_.x > x_border ||rect_.x < 0 || rect_.y < 0 || rect_.y > y_border )
    {
        isMoving = false;
    }
}
