
#pragma once
#ifndef IMAGE_H
#define IMAGE_H
#include "stb_image.h"

typedef struct imageData {
	bool success;
	int width;
	int height;
	int nChannels;
	unsigned char* data;
}ImgData;

class ImageLoader {
public:
	static ImgData getImage(const char*);
};
#endif