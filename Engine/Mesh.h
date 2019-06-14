#pragma once
#include <vector>
#include <gl/glew.h>

class Mesh {

private:
	GLuint vao;
	GLuint vbo;
	int vertexCount;
	int indicesCount;

	


public:
	Mesh(std::vector<float> positions, std::vector<unsigned int> indices);
	
	void draw();
	void destroy();
};
