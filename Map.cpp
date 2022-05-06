#include "Map.h"
#include "Texture.h"
#include <fstream>

Map::Map()
{
    dirt.loadFromFile("map/dirt.png");
    grass.loadFromFile("map/grass.png");
}

Map::~Map()
{}

void Map::loadMap(std::string path)
{
    std::ifstream file(path);

    for(int i=0; i < maxX; i++){
        for(int j=0; j < maxY; j++)
            file>>tileMap[i][j];
    }
}

void Map::drawMap()
{
    for(int i=0; i < maxX; i++){
        for(int j=0; j < maxY; j++){
            switch(tileMap[i][j]){
            case 1:
                grass.setRect(j*TILE_SIZE, i*TILE_SIZE, TILE_SIZE, TILE_SIZE);
                grass.renderTexture(NULL);
                break;
            case 2:
                dirt.setRect(j*TILE_SIZE, i*TILE_SIZE);
                dirt.renderTexture(NULL);
                break;
            }
        }
    }

}
