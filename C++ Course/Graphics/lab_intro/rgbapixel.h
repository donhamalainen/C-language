/**
 * @file rgbapixel.h
 * Definition of the RGBAPixel class for the EasyPNG library.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */

#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H
#include <cstdint>
using std::uint8_t;
class RGBAPixel
{
    public:
    uint8_t red, blue, green, alpha;
    RGBAPixel();
    RGBAPixel(uint8_t _r, uint8_t _g, uint8_t _b);
};
#endif