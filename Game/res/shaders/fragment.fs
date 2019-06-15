#version 400

in vec2 outTextCoord;
out vec4 fragColor;

uniform sampler2D texture_sampler;




void main() {
fragColor = vec4(.5,.5, 0, 1);

  fragColor = texture(texture_sampler, outTextCoord);

  
}