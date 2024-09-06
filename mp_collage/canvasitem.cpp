/**
 * Copyright 2024 University of Oulu
 * Authors:
 *   Elmeri Uotila <roope.uotila@oulu.fi>
 */

#include "canvasitem.h"

CanvasItem::CanvasItem(size_t x, size_t y, Vector2 position, Vector2 scale, RGBAPixel color) {
	resize(x, y);
	
	// Initialize the pixels with default values
    for (size_t i = 0; i < x; ++i) {
        for (size_t j = 0; j < y; ++j) {
            RGBAPixel* p = (*this)(i, j);
            p->alpha = 0;
            p->red = 255;
            p->green = 255;
            p->blue = 255;
        }
    }
	position_ = position;
	color_ = color;
	scale_ = scale;
}

RGBAPixel CanvasItem::getBlendedPixel(size_t x, size_t y){
	RGBAPixel* p = (*this)(x,y);
	RGBAPixel copy = *p;
	
	// Blend the pixel with color_
    copy.red = (copy.red * color_.red) / 255;
    copy.green = (copy.green * color_.green) / 255;
    copy.blue = (copy.blue * color_.blue) / 255;
    copy.alpha = (copy.alpha * color_.alpha) / 255;

	
	return copy;
}

Vector2 CanvasItem::position(){
	return position_;
}

Vector2 CanvasItem::scale(){
	return scale_;
}

void CanvasItem::SetPosition(Vector2 pos){
	position_ = pos;
}