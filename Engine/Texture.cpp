#include "Texture.h"
#include "stb/stb_image.h"
#include <iostream>


Texture::Texture(const char* file) {
	glGenTextures(1, &textureID);
	rgb = stbi_load(file, &width, &height, &bpp, 4);
	if (!rgb) {
		std::cerr << "Failed to load texture " << file << "\n";
		exit(1);
	}


	std::cout << "type: " << bpp << std::endl;


	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, rgb);


	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(rgb);
	std::cout << "Generated texture " << textureID << std::endl;


}

void Texture::destory() {
	glBindTexture(GL_TEXTURE_2D, 0);

	glDeleteTextures(1, &textureID);

	std::cout << "Destroyed texture " << textureID << std::endl;
}
