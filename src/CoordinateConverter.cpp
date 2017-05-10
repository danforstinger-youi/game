//
//  CoordinateConverter.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "CoordinateConverter.h"

int CoordinateConverter::CoordinateToPixels(const int &coordinate)
{
    return coordinate*PIXEL_PER_COORD;
}

int CoordinateConverter::PixelsToCoordinate(const int &pixels)
{
    return pixels/PIXEL_PER_COORD;
}

glm::vec3 CoordinateConverter::CoordinateToPixels(const glm::vec3 &coordinates)
{
    return glm::vec3(coordinates[0]*PIXEL_PER_COORD, coordinates[1]*PIXEL_PER_COORD, coordinates[2]*PIXEL_PER_COORD);
}

glm::vec3 CoordinateConverter::PixelsToCoordinate(const glm::vec3 &pixels)
{
    return glm::vec3(pixels[0]/PIXEL_PER_COORD, pixels[1]/PIXEL_PER_COORD, pixels[2]/PIXEL_PER_COORD);
}



