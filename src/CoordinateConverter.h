//
//  CoordinateConverter.h
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef CoordinateConverter_h
#define CoordinateConverter_h

#include <glm/glm.hpp>

class CoordinateConverter
{
public:
    static int CoordinateToPixels(const int &coordinate);
    static int PixelsToCoordinate(const int &pixel);
    
    static glm::vec3 CoordinateToPixels(const glm::vec3 &coordinates);
;
    static glm::vec3 PixelsToCoordinate(const glm::vec3 &pixels);
    
    static const int PIXEL_PER_COORD = 64;
};

#endif /* CoordinateConverter_h */
