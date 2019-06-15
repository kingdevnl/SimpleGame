#version 400

layout (location=0) in vec4 pos;
layout (location=2) in vec2 textCoord;
out vec2 outTextCoord;


uniform mat4 MVP;


void main() {
	gl_Position = MVP*pos;
	outTextCoord = textCoord;

}