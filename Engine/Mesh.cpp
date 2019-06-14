#include "stdafx.h"
#include "Mesh.h"

Mesh::Mesh(std::vector<float> positions, std::vector<unsigned> indices) {
	vertexCount = positions.size();
	indicesCount = indices.size();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);

	//POS
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), &positions[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
	//END POS

	//INDICES
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 1, GL_UNSIGNED_INT, false, 0, 0);
	//END INDICES


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


}
void Mesh::draw() {
	
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);


	glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindVertexArray(0);

}
void Mesh::destroy() {
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &vbo);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vao);
	std::cout << "Destroyted vbo "<<vbo<<std::endl;
}
