#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec4 Color;



out vec2 v_TexCoord;
out vec4 v_Color;
out vec4 gl_Position;

uniform mat4 u_View;
uniform mat4 u_Proj;
uniform mat4 u_Rotation;


void main()
{
	gl_Position = u_Proj * u_View * position * u_Rotation;
	v_TexCoord = texCoord;
	v_Color = Color;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;
in vec4 v_Color;


float near = 0.0001;
float far = 1000.0;

uniform int u_time;
uniform vec4 u_Color;
uniform vec3 u_Pos;
uniform sampler2D u_Texture;
uniform vec2 u_mouse_pos;



vec2 Resolution = vec2(2500.0f, 2500.0f);

float PI = 3.14159265359f;



float drawLine(vec2 p1, vec2 p2, vec2 uv, float a)
{
	float r = 0.;
	float one_px = 1. / Resolution.x; //not really one px

	// get dist between points
	float d = distance(p1, p2);

	// get dist between current pixel and p1
	float duv = distance(p1, uv);

	//if point is on line, according to dist, it should match current uv 
	r = 1.0f - floor(1. - (a * one_px) + distance(mix(p1, p2, clamp(duv / d, 0., 1.)), uv));

	return r;
}

vec3 Gradient(vec3 Colour, vec2 uv)
{
	Colour[2] -= uv.x;
	Colour[1] += uv.y;
	Colour[0] += uv.x;
   
	return Colour;

}


void main()
{
	vec2 uv = gl_FragCoord.xy / Resolution.xy;


	vec3 col = 0.5 + 0.5 * cos((float(u_time) / 10.0f) + uv.xyx + vec3(0, 2, 4));
	float Val = drawLine(vec2(0.0f, 0.0f), vec2(float(u_mouse_pos.x) / Resolution.x,  (float(u_mouse_pos.y) / Resolution.y)), uv, 10.0f);

	if (Val != 1)

	{
		vec3 col = Gradient(vec3(vec2(((float(u_mouse_pos.x) / Resolution.x) * 3.0f), (float(u_mouse_pos.y) / Resolution.y) * 3.0f), ((float(u_mouse_pos.x) / Resolution.x) * 3.0f)), uv);
		color = vec4(col, 1.0);
	}
	else {
		vec3 col = 0.5 + 0.5 * cos((float(u_time) / 10.0f) + uv.xyx + vec3(0, 2, 4));
		color = vec4(col, 1.0);

	}

	/*
	vec2 uv = gl_FragCoord.xy / (Resolution.xy);
    vec3 col = 0.5 + 0.5 * cos((float(u_time)/14.0f)+ uv.xyx + vec3(0, 2, 4));
	color = vec4(col, 1.0);
	*/
}