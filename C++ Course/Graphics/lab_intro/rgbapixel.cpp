/**
 * @file rgbapixel.cpp
 * Implementation of the RGBAPixel class for the EasyPNG library.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#include "rgbapixel.h"

RGBAPixel::RGBAPixel(){
    red = green = blue = alpha = 255;
};

RGBAPixel::RGBAPixel(uint8_t _r, uint8_t _g, uint8_t _b){
    red = _r;
    green = _g;
    blue = _b;
    alpha = 255;
}