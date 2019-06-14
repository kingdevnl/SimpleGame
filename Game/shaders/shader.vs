#version 400


layout (location=0) in vec3 position;
uniform float u_Scale;
void main() {

gl_Position = vec4(position, u_Scale);
	
}