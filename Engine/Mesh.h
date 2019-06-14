#pragma once
#include <vector>
#include <gl/glew.h>
#include "Texture.h"
class Texture;

class Mesh {

private:
	GLuint vao;
	GLuint vbo;
	int vertexCount;
	int indicesCount;
	Texture* texture;

	


public:
	Mesh(std::vector<float> positions, std::vector<unsigned int> indices, std::vector<float> textCoords, Texture* texture);
	bool hasTexture() {
		return texture != nullptr;
	}
	void draw();
	void destroy();
};
