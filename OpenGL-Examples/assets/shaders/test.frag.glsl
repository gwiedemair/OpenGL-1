#version 450 core

layout (location = 0) out vec4 o_FragColor;

in vec2 v_TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	// linearly interpolate between both textures
	o_FragColor = mix(texture(texture1, v_TexCoord), texture(texture2, v_TexCoord), 0.2);
}