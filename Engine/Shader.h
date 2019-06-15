#pragma once
#include <string>
#include <gl/glew.h>
#include <glm/glm.hpp>

class Shader {
private:
	std::string vertexCode;
	std::string fragmentCode;

	int programID, vertexID, fragmentID;


public:
	Shader(const std::string& vertex_code, const std::string& fragment_code)
		: vertexCode(vertex_code),
		  fragmentCode(fragment_code) {}

	GLuint getUniform(const char* uniform) {
		return glGetUniformLocation(programID, uniform);
	}

	void setup();
	void bind();

	inline void setUniform1f(const char* name, float val) {
		glUniform1f(getUniform(name), val);
	}

	inline void setUniformMat4f(const char* name, glm::mat4 matrix) {
		glUniformMatrix4fv(getUniform(name), 1, GL_FALSE, &matrix[0][0]);
	}

	void unbind();
	void destroy();

	int getProgramID() {
		return programID;
	}

	

	static Shader load(const char* vertexPath, const char* fragmentPath);
};
