#pragma once
#include <string>
#include <gl/glew.h>

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

	void setUniform1f(const char* name, float obj) {
		GLuint loc = getUniform(name);

		glUniform1f(loc, obj);
	}
	void setUniform3f(const char* name, float x, float y, float z) {
		GLuint loc = getUniform(name);

		glUniform3f(loc, x, y, z);
	}
	void setUniform4f(const char* name, float x, float y, float z, float a) {
		GLuint loc = getUniform(name);

		glUniform4f(loc, x, y, z, a);
	}
	void unbind();
	void destroy();

	int getProgramID() {
		return programID;
	}

	static Shader load(const char* vertexPath, const char* fragmentPath);
};
