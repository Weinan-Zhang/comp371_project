#version 330 core


in vec3 fragment_color;
in vec4 shadow_map_pos;
in vec2 uv;

out vec3 color;


uniform sampler2D texture_sampler;
uniform sampler2DShadow shadow_map;


void main()
{
	float visibility = 1.0;

	visibility = texture(shadow_map, vec3(shadow_map_pos.xy/shadow_map_pos.w, shadow_map_pos.z/shadow_map_pos.w));

	//color = fragment_color;
	color = texture(texture_sampler, uv).rgb;

	//color = vec3(texture(shadow_map, vec3(shadow_coord.xy/shadow_coord.w, shadow_coord.z/shadow_coord.w)));
}