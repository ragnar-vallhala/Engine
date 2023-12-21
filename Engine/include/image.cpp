#include "image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


ImgData ImageLoader::getImage(const char* path)
{
	int width, height, nChannels;
	unsigned char* data = stbi_load(path, &width, &height, &nChannels, 0);
	bool success = false;
	if (data)
		success = true;
	return ImgData(success, width, height, nChannels, data);
}
