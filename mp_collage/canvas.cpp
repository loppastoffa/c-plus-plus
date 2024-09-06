/**
 * Copyright 2024 University of Oulu
 * Authors:
 *   Elmeri Uotila <roope.uotila@oulu.fi>
 */

#include "canvas.h"
#include <algorithm>
#include <iostream>

Canvas::Canvas()
{
	items.reserve(10);
}

// Just delete the list, the individual items are handled by main
Canvas::~Canvas()
{
}

// Add an item at the end of the list
void Canvas::Add(CanvasItem* item)
{
	// Add an item at the end of the vector
    items.push_back(item);
}

// Find and remove pointer from list
// But don't free the memory, leave that to main
// If pointer is not found, do nothing
void Canvas::Remove(CanvasItem* item)
{
	// Find and remove the item pointer from the vector
    auto it = std::find(items.begin(), items.end(), item);

    if (it != items.end()) {
        items.erase(it);
    }
}

// Find given items from list and swap their positions
// Swap only if both pointers are found
void Canvas::Swap(CanvasItem* item1, CanvasItem* item2)
{
	// Find the positions of item1 and item2 in the vector
    auto it1 = std::find(items.begin(), items.end(), item1);
    auto it2 = std::find(items.begin(), items.end(), item2);
    
    // Swap if both items are found
    if (it1 != items.end() && it2 != items.end() && it1 != it2) {
        std::iter_swap(it1, it2);
    }
}

// Draws all items in the list in order
// Blends the pixels colors of the items with their item color
// Draws the items in their given position and scales them accordingly
// Blends drawn layers based on alpha channel (transparency)
void Canvas::draw(PNG* canvas) const
{
	for(const auto& item : items) {
		for(size_t x = 0; x < item->width(); x++){
			for(size_t y = 0; y < item->height(); y++){
				// This gets the pixel color blended with item color
				// Check canvasitem.cpp
				RGBAPixel coli = item->getBlendedPixel(x,y);
				Vector2 sc = item->scale();
				
				// You should uncomment the below line and use in the section belowitems.reserve(10);
				Vector2 pos = item->position();
				
				for(int xs = 0; xs < std::abs(static_cast<int>(sc.x() - 0.001)) + 1; xs++){
					for(int ys=0; ys < std::abs(static_cast<int>(sc.y() - 0.001)) + 1; ys++){

						int x1 = x * sc.x() + pos.x() + xs;
                        int y1 = y * sc.y() + pos.y() + ys;
						
						// Check that it's within bounds
						if(x1 >= 0 && x1 < (int)canvas->width() && y1 >= 0 && y1 < (int)canvas->height()) {
							// Current color of the canvas
							RGBAPixel* colc = (*canvas)(x1,y1);
							
							colc->red = (coli.red * coli.alpha + colc->red * (255 - coli.alpha)) / 255;
                            colc->green = (coli.green * coli.alpha + colc->green * (255 - coli.alpha)) / 255;
                            colc->blue = (coli.blue * coli.alpha + colc->blue * (255 - coli.alpha)) / 255;
							
							colc->alpha = 255;
						}
					}
				}
			}
		}
	}
}
