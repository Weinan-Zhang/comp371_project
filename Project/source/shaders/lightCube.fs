#version 330 core

// Ouput to fragment shader
out vec4 color;

in vec4 v_color;
in vec3 normal; // You will need this when you do per-fragment lighting

void main()
{
	// set the fragment color to the interpolated vertex color
	color = vec4(v_color.rgb, 1);
}