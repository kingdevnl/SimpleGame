#include "Texture.h"
#include "stb/stb_image.h"
#include <iostream>


Texture::Texture(const char* file) {
	glGenTextures(1, &textureID);
	rgb = stbi_load(file, &width, &height, &bpp, 3);
	if (!rgb) {
		std::cerr << "Failed to load texture " << file << "\n";
		exit(1);
	}

	

	std::cout << bpp;
	

	glBindTexture(GL_TEXTURE_2D, textureID);

	if(bpp == 3) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, rgb);
	} else if(bpp = 4) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, rgb);

	}
	
	glGenerateMipmap(GL_TEXTURE_2D);


	std::cout << "Generated texture " << textureID << std::endl;


}

void Texture::destory() {
	glBindTexture(GL_TEXTURE_2D, 0);

	glDeleteTextures(1, &textureID);
	stbi_image_free(rgb);
	std::cout << "Destroyed texture " << textureID << std::endl;
}
