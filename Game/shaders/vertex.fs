#version 400

layout (location=0) in vec3 pos;
layout (location=2) in vec2 textCoord;
out vec2 outTextCoord;

void main() {
	gl_Position = vec4(pos, 1);
	outTextCoord = textCoord;

}