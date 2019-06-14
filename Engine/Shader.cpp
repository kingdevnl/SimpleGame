#include "stdafx.h"
#include "Shader.h"
#include <fstream>


char* getShaderError(int id) {
	int lenght;
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
	char* msg = new char[lenght];
	glGetShaderInfoLog(id, lenght, &lenght, msg);
	return msg;
}

void compileShader(int id, bool isVertex) {
	glCompileShader(id);
	GLint status;
	glGetShaderiv(id, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE) {
		int lenght;

		std::cout << "Failed to compile shader: " << id << " isVertex: " << isVertex << " " << getShaderError(id) << std
			::endl;
		exit(1);
	}
	std::cout << "Compiled shader: " << id << std::endl;

}


void Shader::setup() {
	programID = glCreateProgram();
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	const char* vertex = vertexCode.c_str();
	const char* fragment = fragmentCode.c_str();

	glShaderSource(vertexID, 1, &vertex, NULL);
	glShaderSource(fragmentID, 1, &fragment, NULL);
	compileShader(vertexID, true);
	compileShader(fragmentID, false);

	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);
	glLinkProgram(programID);
	GLint status;
	glGetShaderiv(programID, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		std::cout << "Failed to link shader: " << programID << " " << getShaderError(programID) << std::endl;
		exit(1);
	}

	glValidateProgram(programID);

	glGetShaderiv(programID, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		std::cout << "Failed to validate shader: " << programID << " " << getShaderError(programID) << std::endl;
		exit(1);
	}


	std::cout << "Created shader " << programID << " vsID: " << vertexID << " fragID: " << fragmentID << std::endl;
}

void Shader::bind() {
	glUseProgram(programID);
}




void Shader::unbind() {
	glUseProgram(0);

}

void Shader::destroy() {
	glDetachShader(programID, vertexID);
	glDetachShader(programID, fragmentID);
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
	glDeleteProgram(programID);


	std::cout << "Destroyed shader " << programID << std::endl;
}

Shader Shader::load(const char* vertexPath, const char* fragmentPath) {

	std::ifstream vertexFile(vertexPath);
	std::ifstream fragmentFile(fragmentPath);

	return Shader(
		std::string(
			std::istreambuf_iterator<char>(vertexFile),
			std::istreambuf_iterator<char>()
		),
		std::string(
			std::istreambuf_iterator<char>(fragmentFile),
			std::istreambuf_iterator<char>()
		)

	);
}
