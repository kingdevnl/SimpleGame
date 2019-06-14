#version 400

layout (location=0) out vec4 color;

uniform vec4 u_Color;

void main() {
   color = vec4(.5,.5, 0, 1);
   //color = u_Color;
} 