#pragma once
#include <gl/glew.h>
class Texture {
private:
	int width, height, bpp;
	unsigned char* rgb;
	GLuint textureID;
	
public:
	Texture(const char* file);

	void destory();
	GLuint getTextureID() {
		return textureID;
	}

};

